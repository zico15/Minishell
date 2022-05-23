/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:15:24 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 17:12:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_base_array.h>
#include <ft_util.h>

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

static void	base_remove_element_index(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return (NULL);
	e = (this()->array)->begin;
	while (e)
	{
		if (i == index)
		{
			(this()->array)->remove(e);
			return ;
		}
		e = e->next;
		i++;
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
		a->remove_index = base_remove_element_index;
		a->free_element = ft_free_element;
	}
	return (a);
}

