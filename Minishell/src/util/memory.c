/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 22:40:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/util.h"

int	free_ob(void *v)
{
	if (v)
		free(v);
	return (1);
}

int	free_list(void *l)
{
	int		i;
	void	**v;

	v = (void **) l;
	i = 0;
	if (v)
	{
		while (v[i])
		{
			free(v[i]);
		}
		free(v);
	}
	return (i);
}
