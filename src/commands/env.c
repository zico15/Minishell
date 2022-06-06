/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/06 21:30:46 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_string.h>

static void	print_env(t_element *e, void *v)
{
	t_command	*this;

	this = v;
	(void) e;
	/*if (string().equals(e->key, __MINISHELL_PID__))
		return ;*/
	/*
	write(this->fd[1], e->key, string().size(e->key));
	write(this->fd[1], "=", 1);*/
	write(this->fd[1], e->value, string().size(e->value));
	write(this->fd[1], "\n", 1);
}

static int	*ft_input(t_command *previou, t_command *this)
{
	int	fd;

	fd = this->fd[1];
	if (!this->next || this->is_print)
		this->fd[1] = 1;
	if (terminal()->envp)
		(hashmap(terminal()->envp))->for_each(print_env, this);
	this->fd[1] = fd;
	close(this->fd[1]);
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_env(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}

void	init_env(t_terminal *t)
{
	int			i;
	char		**str;
	t_element	*e;

	i = -1;
	while (terminal()->envp_to_str && terminal()->envp_to_str[++i])
	{
		str = string().split(terminal()->envp_to_str[i], "=");
		if (string().size_list(str) > 1)
		{
			(hashmap(t->envp))->put(string().copy(str[0]), \
			string().copy(str[1]));
		}
		free_list(str);
	}
	e = hashmap(t->envp)->get_key(__MINISHELL_PID__);
	if (e)
		t->pid_parent = string().atoi(e->value);
	(hashmap(t->envp))->put(__MINISHELL_PID__, string().itoa(getpid()));
	terminal()->envp_to_str = hashmap(terminal()->envp)->to_str();
}
