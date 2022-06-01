/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 18:55:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_string.h>

static void	print_env(t_element *e, void *v)
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
	if (terminal()->envp)
		(hashmap(terminal()->envp))->for_each(print_env, this);
	close(this->fd[1]);
	next_command(previou, this);
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

void	init_env(t_terminal *t)
{
	int			i;
	char		**str;
	t_element	*e;

	i = -1;
	while (data()->envp && data()->envp[++i])
	{
		str = string().split(data()->envp[i], "=");
		if (string().size_list(str) > 1)
			(hashmap(t->envp))->put(str[0], str[1]);
	}
	e = hashmap(t->envp)->get_key(__MINISHELL_PID__);
	if (e)
		t->pid_parent = string().atoi(e->value);
	(hashmap(t->envp))->put(__MINISHELL_PID__, string().itoa(getpid()));
	data()->envp = hashmap(terminal()->envp)->to_str();
}
