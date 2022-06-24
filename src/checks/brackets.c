/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:16:29 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 18:54:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

char	*check_bracket(const char *str)
{
	char	buff[BUFFER_SIZE];
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	while (str[++i])
	{
		if ((str[i] == '(' || str[i] == ')') && is_quotes(str, i) == NOT_QUOTED)
			continue ;
		else
			buff[j++] = str[i];
	}
	buff[j] = 0;
	return (string().copy(buff));
}

static char	*code_nivel_priority(void)
{
	static char	code[3] = {26, ':', 0};

	return (code);
}

char	*create_code_nivel_priority(int i)
{
	char	*temp;
	char	*str;

	temp = string().itoa(i);
	str = string().join(code_nivel_priority(), temp);
	free_ob(temp);
	return (str);
}

void	check_nivel_priority_teste(char *str)
{
	if (string().equals_n(str, code_nivel_priority(), 2))
		printf("code_nivel_priority: OK\n");
	else
		printf("code_nivel_priority: KO\n");
}

void	check_nivel_priority(t_command *this)
{
	int	i;

	i = -1;
	if (!this || !this->commands)
		return ;
	while (this->commands[++i])
	{
		if (string().equals_n(this->commands[i], code_nivel_priority(), 2))
			printf("code_nivel_priority: OK");
		else
			printf("code_nivel_priority: KO");
	}
}
/*
void	check_bracket(t_command *this)
{
	int	i;

	if (!this->commands)
		return ;
	i = -1;
	while (this->commands[++i])
	{
		if (string().contains(this->commands[i], "(") \
		|| string().contains(this->commands[i], ")"))
			this->commands[i] = remove_bracket(this->commands[i]);
	}
}*/
