/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/08 19:53:43 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

// static void print_e(t_element *e, void *o)
// {
// 	(void) o;
// 	printf("T: (%s)\n", e->value);
// }

// static void print_l(t_element *e, void *o)
// {
// 	void *l;

// 	l = e->value;
// 	printf("================\n");
// 	array(l)->for_each(print_e, o);
// }

void	*token(char *line)
{
	void	*token;
	void	*list;

	if (!line)
	{
		terminal()->destroy("exit");
		return (NULL);
	}
	if (!*line)
		return (NULL);
	list = ft_divide_quotes(line);
	token = ft_divide_cmds(list);
	return (token);
}
