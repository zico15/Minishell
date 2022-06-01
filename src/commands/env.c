/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 11:07:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

void	fun(t_element *e, void *v)
{
	t_command	*this;

	this = v;
	if (string().equals(e->key, __MINISHELL_PID__))
		return ;
	write(this->fd[1], e->key, string().size(e->key));
	write(this->fd[1], "=", 1);
	write(this->fd[1], e->value, string().size(e->value));
	write(this->fd[1], "\n", 1);
}

static int	*ft_input(t_command *previou, t_command *this)
{
	(hashmap(terminal()->envp))->for_each(fun, this);
	close(this->fd[1]);
	next_command(previou, this);
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}

t_command	*new_env(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
