/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_hasmap_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:13:48 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/27 16:53:14 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_base_array.h>
#include <ft_util.h>
#include <ft_string.h>

static t_element	*__put(char *key, void	*value)
{
	t_element_hasmap	*v;

	v = malloc(sizeof(t_element_hasmap));
	if (!v)
		return (0);
	v->key = key;
	v->value = value;
	return (array(this()->hasmap->list)->add(v));
}

static void	*__get_index(int index)
{
	t_element_hasmap	*e;

	e = (t_element_hasmap *) array(this()->hasmap->list)->get(index);
	if (e)
		return (e->value);
	return (NULL);
}

static void	*__get_key(char *key)
{
	t_element_hasmap	*e;
	int					size;
	int					i;

	size = array(this()->hasmap->list)->size;
	i = -1;
	while (++i < size)
	{
		e = (t_element_hasmap *) array(this()->hasmap->list)->get(i);
		if (!e)
			return (0);
		if (string().equals(e->key, key))
			return (e->value);
	}
	return (NULL);
}

void	*new_hasmap(void)
{
	t_hasmap	*a;

	a = malloc(sizeof(t_hasmap));
	if (a)
	{
		a->list = new_array();
		a->put = __put;
		a->get_index = __get_index;
		a->get_key = __get_key;
		hasmap(a);
	}
	return (a);
}
