/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:16:29 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/17 21:46:46 by edos-san         ###   ########.fr       */
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
