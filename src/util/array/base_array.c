/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 23:15:24 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/25 20:44:34 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_base_array.h>
#include <ft_util.h>

void	__base_for_each(void (*fun)(t_element *e))
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

t_element	*__base_set_element(int index, void *value)
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
			if (e->value)
				free(e->value);
			e->value = value;
			return (e);
		}
		e = e->next;
		i++;
	}
	return (0);
}

void	__base_remove_element_index(int index)
{
	int			i;
	t_element	*e;

	i = 0;
	if (!this()->array)
		return ;
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

int	__base_free_element(void *value)
{
	if (value)
		free(value);
	return (1);
}

t_array	*array(t_array *a)
{
	this()->array = a;
	return (a);
}
