/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 16:29:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

char	*get_path(t_command	*c, char *arg, const char *path)
{
	int		i[2];

	i[0] = 0;
	path = path + 5;
	while (path && *path)
	{
		i[1] = 0;
		c->path[i[0]] = *path++;
		if (c->path[i[0]] && c->path[i[0]] != ':' && i[0]++ < 100)
			continue ;
		c->path[i[0]++] = '/';
		while (arg && arg[i[1]] && arg[i[1]] != ' ' && arg[i[1]] != '\t')
			c->path[i[0]++] = arg[i[1]++];
		c->path[i[0]] = 0;
		if (access(c->path, F_OK) == -1)
			i[0] = 0;
		else
			break ;
	}
	if (access(c->path, F_OK) == -1)
		c->path[0] = 0;
	return (NULL);
}

void	next_command(t_command *this)
{
	if (this && this->next)
	{
		this->next->input(this, this->next);
	}
}
