/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:58:46 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/31 21:07:35 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

void	check_wildcards(t_command *this)
{
	char		*str;
	char		*paths;
	char		*exts;

	str = this->arg;
	if (string().size(str) > 1 && string().contains(str, "*"))
	{
		paths = terminal()->wildcards(str);
		if (paths)
		{
			exts = terminal()->get_exts(str);
			this->arg = string().replace(str, paths, exts);
			free_ob(str);
		}
	}
}

void	__check_args(t_command *this)
{
	int	i;

	i = -1;
	if (!this)
		return ;
	check_wildcards(this);
	this->commands = string().split(this->arg, " ");
	i = -1;
	if (!this->path[0] && !access(this->commands[0], F_OK) && this->commands)
	{
		while (this->commands[0] && this->commands[0][++i])
			this->path[i] = this->commands[0][i];
		this->path[i] = 0;
	}
}
