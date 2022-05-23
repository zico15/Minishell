/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:15:24 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 22:25:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_base_array.h"
#include "../../../headers/util.h"

static void	ft_for_each(void (*fun)(t_element *e))
{
	t_element	*temp;
	t_element	*select;

	if (!this()->array)
		return ;
	temp = (this()->array)->begin;
	while (temp)
	{
		select = temp;
		temp = temp->next;
		fun(select);
	}
}

static int	ft_free_element(void *value)
{
	if (value)
		free(value);
	return (1);
}

t_array	*array(t_array *a)
{
	this()->array = a;
	if (a && !a->for_each)
	{
		a->for_each = ft_for_each;
		a->free_element = ft_free_element;
	}
	return (a);
}

