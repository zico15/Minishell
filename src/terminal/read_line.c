/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 00:24:24 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/01 01:17:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

char	*read_line(t_terminal *t)
{
	char		line[BUFFER_SIZE];
	int			i;
	t_element	*e;

	t = this()->terminal;
	if (!t)
		return (NULL);
	write(0, t->title, string().size(t->title));
	i = read(1, line, BUFFER_SIZE);
	line[i] = 0;
	e = array(this()->read->history)->add(string().copy(line));
	return (e->value);
}

t_read	*new_read_line(void)
{
	t_read	*r;

	r = malloc(sizeof(t_read));
	if (!r)
		return (0);
	r->history = new_array();
	r->lines = new_array();
	this()->read = r;
	return (r);
}
