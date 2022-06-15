/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:02:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/15 12:35:47 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static	void	cread_cmd(int fd, t_command *this, char **arg)
{
	t_command	*c;

	if (!arg)
		return ;
	c = terminal()->get_cmd(*arg);
	c->init(c, arg);
	terminal()->check_command_args(c);
	close(c->fd[0]);
	close(c->fd[1]);
	c->next = this->next;
	c->execute(c, fd, this->fd[1]);
	this->status = c->status;
	this->pid = c->pid;
	c->destroy(c);
}

static char	**cread_new_arg(char **arg)
{
	void	*list;
	char	**new;
	int		i;

	list = new_array();
	i = 1;
	while (arg[++i])
		array(list)->add(string().copy(arg[i]));
	new = array(list)->to_str();
	array(list)->destroy();
	return (new);
}

static int	*input(t_command *previou, t_command *this)
{
	int			fd_open;

	fd_open = 0;
	if (string().size_list(this->commands) >= 3)
	{
		fd_open = open(this->commands[1], O_RDONLY);
		if (fd_open >= 0)
			cread_cmd(fd_open, this, cread_new_arg(this->commands));
	}
	else
		close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_redirect_input(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = input;
	return (c);
}
