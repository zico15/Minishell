/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 22:26:36 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 19:26:14 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_pipex.h"

t_list_cmd	*list(t_list_cmd *t)
{
	this()->list = t;
	return (this()->list);
}

void	list_clear(t_command **c)
{
	int	i;

	i = 0;
	if (c && *c)
	{
		(*c)->destroy(*c);
		*c = NULL;
	}
}
