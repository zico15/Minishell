/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 17:12:24 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

int	free_ob(void *v)
{
	if (v)
		free(v);
	return (1);
}

int	free_list(char **str)
{
	int		i;

	if (str)
	{
		i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
		return (i);
	}
	return (0);
}
