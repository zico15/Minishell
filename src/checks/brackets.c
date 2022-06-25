/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:16:29 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 10:24:19 by edos-san         ###   ########.fr       */
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

/******
 * create_code_nivel_priority
 * *****/
char	*create_priority(int n)
{
	char	*temp;
	char	*str;

	if (n <= 0)
		return (NULL);
	temp = string().itoa(n);
	str = string().join(code_nivel_priority(), temp);
	free_ob(temp);
	return (str);
}

void	check_nivel_priority(t_command *this)
{
	int		i;
	int		nivel;
	void	*args;
	char	*temp;

	i = -1;
	args = new_array();
	while (this->commands && this->commands[++i])
	{
		if (string().equals_n(this->commands[i], code_nivel_priority(), 2))
		{
			temp = this->commands[i];
			nivel = string().atoi((temp + 2));
			if (i == 1)
				this->nivel_priority = nivel;
			else if (!this->nivel_priority || this->nivel_priority != nivel)
				this->status = 258;
		}
		else
			array(args)->add(string().copy(this->commands[i]));
	}
	free_list(this->commands);
	this->commands = array(args)->to_str();
	array(args)->destroy();
}
