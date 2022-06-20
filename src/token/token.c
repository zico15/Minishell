/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/20 16:10:43 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

void	command_destroy_element(t_element	*e)
{
	t_command	*c;

	c = e->value;
	if (c)
		c->destroy(c);
	free_ob(e->key);
	free_ob(e);
}

static void	token_destroy_element(t_element	*e)
{
	void	*list;
	void	*this_list;

	list = e->value;
	this_list = this()->array;
	if (list)
		array(list)->destroy();
	array(this_list);
	free_ob(e->key);
	free_ob(e);
}

void	set_fun_destroy_token(t_element *e, void *o)
{
	(void) o;
	(void) e;
	e->destroy = token_destroy_element;
}

static void	take_quotes(void *token, int i)
{
	void	*list;
	int		j;

	while (++i < array(token)->size)
	{
		j = -1;
		list = array(token)->get(i);
		while (++j < array(list)->size)
		{
			array(list)->set(j, ft_rmv_quotes(array(list)->get(j)));
		}
	}
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
	token = ft_divide_cmds(list, 0, 0);
	take_quotes(token, -1);
	array(list)->destroy();
	free_ob(line);
	return (token);
}
