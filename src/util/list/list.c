/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:26:36 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 16:30:43 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

t_list_cmd	*list(t_list_cmd *t)
{
	this()->list = t;
	return (this()->list);
}

void	list_clear(t_command **c)
{
	if (c && *c)
	{
		(*c)->destroy(*c);
		*c = NULL;
	}
}
