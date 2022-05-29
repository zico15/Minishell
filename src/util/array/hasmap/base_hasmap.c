/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 11:24:09 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_base_array.h>
#include <ft_base_array_util.h>
#include <ft_util.h>


static int	base_destroy_hashmap(void)
{
	if (!this()->hashmap)
		return (0);
	array(this()->hashmap->list)->destroy();
	free_ob(this()->hashmap);
	this()->hashmap = NULL;
	return (1);
}

static int	base_size_hashmap(void)
{
	if (!this()->hashmap)
		return (0);
	return (array(this()->hashmap->list)->size);
}

t_hashmap	*hashmap(t_hashmap *a)
{
	if (a)
		this()->array = a->list;
	this()->hashmap = a;
	return (a);
}

void	*new_hashmap(void)
{
	t_hashmap	*a;

	a = malloc(sizeof(t_hashmap));
	if (a)
	{
		a->list = new_array();
		a->put = __put_hasmap;
		a->get_index = __get_index_hasmap;
		a->get_key = __get_key_hasmap;
		a->remove_index = __remove_index_hasmap;
		a->remove_key = __remove_element_hasmap;
		a->destroy = base_destroy_hashmap;
		a->for_each = __base_for_each;
		a->size = base_size_hashmap;
		hashmap(a);
	}
	return (a);
}
