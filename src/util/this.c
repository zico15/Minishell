/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:06:50 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/04 09:54:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>

t_this	*this(void)
{
	static t_this	t;

	return (&t);
}

t_terminal	*terminal(void)
{
	return (this()->terminal);
}

t_array	*array(t_array *a)
{
	this()->array = a;
	return (a);
}
