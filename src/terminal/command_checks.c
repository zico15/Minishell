/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:58:46 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/28 17:31:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

void	check_wildcards(t_command *this)
{
	int			i;
	char		*str;
	char		*paths;

	i = 1;
	if (string().size_list(this->commands) < 2)
		return ;
	while (this->commands[i])
	{
		str = this->commands[i];
		if (string().equals_n(str, "*.", 2))
		{
			paths = terminal()->wildcards(str + 1);
		}
	}
}

void	__check_args(t_command *this)
{
	check_wildcards(this);
}
