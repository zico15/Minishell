/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:58:46 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 10:05:26 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

void	check_wildcards(t_command *this)
{
	int			i;
	char		*str;
	char		*paths;
	char		*temp;

	i = 1;
	if (string().size_list(this->commands) < 2)
		return ;
	while (this->commands[i])
	{
		str = this->commands[i];
		if (string().contains(str, "*"))
		{
			paths = terminal()->wildcards(str + 1);
			if (paths)
			{
				temp = str;
				this->commands[i] = string().replace(temp, paths, "*.c");
			}
		}
	}
}

void	__check_args(t_command *this)
{
	check_wildcards(this);
}
