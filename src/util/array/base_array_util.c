/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:51:06 by edos-san          #+#    #+#             */
/*   Updated: 2022/02/20 13:51:06 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_base_array.h"
#include "../../../headers/util.h"

static t_element	*base_add_element(void *value)
{
	t_element	*e;

	if (!this()->array)
		return (NULL);
	e = malloc(sizeof(t_element));
	if (!e)
		return (NULL);
	e->value = value;
	e->next = NULL;
	if (!(this()->array)->begin)
		(this()->array)->begin = e;
	else
		(this()->array)->end->next = e;
	(this()->array)->end = e;
	(this()->array)->size++;
	return (e);
}

static void	*base_get_element(int index)
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
			return (e->value);
		e = e->next;
		i++;
	}
	return (0);
}

static t_element	*base_remove_element(t_element	*e)
{
	t_element	*b;
	t_element	*t;

	if (!this()->array || !e)
		return (NULL);
	b = (this()->array)->begin;
	while (b)
	{
		t = b;
		if (b == e)
		{
			if (t == b)
				(this()->array)->begin = b->next;
			else
				t->next = b->next;
			if ((this()->array)->free_element && b->value)
				(this()->array)->free_element(b->value);
			free(b);
			if ((this()->array)->size-- >= 0 && !(this()->array)->size)
				(this()->array)->end = 0;
			return (e);
		}
		b = b->next;
	}
	return (e);
}

static int	base_destroy(void)
{
	t_element	*b;
	t_element	*e;

	if (!this()->array)
		return (0);
	b = (this()->array)->begin;
	while (b && --(this()->array)->size)
	{
		e = b;
		b = b->next;
		if ((this()->array)->free_element && e->value)
			(this()->array)->free_element(e->value);
		if (e)
			free(e);
	}
	free(this()->array);
	this()->array = NULL;
	return (1);
}

void	*new_array(void)
{
	t_array	*a;

	a = malloc(sizeof(t_array));
	if (a)
	{
		a->size = 0;
		a->begin = NULL;
		a->end = NULL;
		a->add = base_add_element;
		a->get = base_get_element;
		a->remove = base_remove_element;
		a->destroy = base_destroy;
		array(a);
	}
	return (a);
}
