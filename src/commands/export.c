/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/12 21:03:13 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	print_declare(t_element *e, void *o)
{
	t_command	*this;

	this = o;
	if (string().equals(e->key, __MINISHELL_PID__))
		return ;
	write(this->fd[1], "declare -x ", 11);
	write(this->fd[1], e->key, string().size(e->key));
	write(this->fd[1], "=\"", 2);
	write(this->fd[1], e->value, string().size(e->value));
	write(this->fd[1], "\"\n", 2);
}

static void	put_env(t_command *this)
{
	char	**str;
	char	*temp;

	temp = this->commands[1];
	str = string().split(temp, "=");
	if (string().size_list(str))
	{
		(hashmap(terminal()->envp))->put(str[0], str[1]);
		free_ob(str);
	}
	else
		free_list(str);
	if (temp && terminal()->pid_parent != -1)
	{
		temp = string().join("export ", temp);
		ft_send_msg(terminal()->pid_parent, temp);
		free_ob(temp);
	}
}

static int	*ft_input(t_command *previou, t_command *this)
{
	if (string().size_list(this->commands) > 1 && \
	string().contains(this->commands[1], "="))
		put_env(this);
	else
		(hashmap(terminal()->envp))->for_each(print_declare, this);
	close(this->fd[1]);
	terminal()->update_env();
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_export(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}

void	export_add(t_terminal	*t, char *str)
{
	char		**list;

	if (!t || !str || !*str)
		return ;
	list = string().split(str, " =");
	if (!list || !string().equals(*list, "export"))
	{
		free_list(list);
		return ;
	}
	if (string().size_list(list) > 1)
		(hashmap(t->envp))->put(list[1], list[2]);
	terminal()->update_env();
	ft_send_msg(terminal()->pid_parent, str);
	free_ob(list);
}
