/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/19 11:10:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
#include <ft_string.h>
#include <ft_command_util.h>
#include <termios.h>

static void	print_env(t_element *e, void *v)
{
	t_command	*this;

	this = v;
	(void) e;
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
	return (terminal()->next_command(previou, this));
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

static void	update_env_base(t_terminal *t)
{
	t_element	*e;
	char		*key_pid;
	char		*key_shlvl;

	key_pid = string().copy(__MINISHELL_PID__);
	key_shlvl = string().copy("SHLVL");
	e = hashmap(t->envp)->get_key(key_pid);
	if (e)
		t->pid_parent = string().atoi(e->value);
	e = hashmap(t->envp)->get_key(key_shlvl);
	if (e)
		t->shlvl = string().atoi(e->value) + 1;
	(hashmap(t->envp))->put(key_shlvl, string().itoa(t->shlvl));
	(hashmap(t->envp))->put(key_pid, string().itoa(getpid()));
	hashmap(t->envp)->remove_key("OLDPWD");
	free_list(terminal()->envp_to_str);
	terminal()->envp_to_str = hashmap(terminal()->envp)->to_str();
}

void	init_env(t_terminal *t)
{
	int				i;
	char			**str;
	struct termios	ter;

	tcgetattr(0, &ter);
	ter.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &ter);
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
	terminal()->envp_to_str = NULL;
	update_env_base(t);
}
