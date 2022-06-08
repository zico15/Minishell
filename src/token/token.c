/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/08 22:51:58 by edos-san         ###   ########.fr       */
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
void	command_destroy_element(t_element	*e)
{
	t_command	*c;

	printf("command_destroy_element\n");
	c = e->value;
	if (c)
		c->destroy(c);
	free_ob(e->value);
	free_ob(e->key);
	free_ob(e);
}

void	token_destroy_element(t_element	*e)
{
	void	*list;

	list = e->value;
	if (list)
		array(list)->destroy();
	e->value = NULL;
	free_ob(e->key);
	free_ob(e);
}

void	*token(char *line)
{
	void	*token;
	void	*list;

	if (!line)
		terminal()->destroy("exit");
	if (!*line)
		return (NULL);
	list = ft_divide_quotes(line);
	token = ft_divide_cmds(list);
	return (token);
}
