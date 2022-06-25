/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 21:00:11 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

int	*cread_cmd(t_command *previou, t_command *this, char **arg)
{
	t_command	*c;

	if (!arg)
		return (terminal()->next_command(previou, this));
	c = terminal()->get_cmd(*arg);
	c->init(c, arg);
	c->next = this->next;
	this->next = c;
	(terminal())->next_command(previou, this);
	this->status = c->status;
	this->pid = c->pid;
	return (this->fd);
}

char	**cread_new_arg(char **arg)
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

static void	heredoc(t_command *this, char *end)
{
	char	*str;

	str = NULL;
	close(this->fd[0]);
	close(this->fd[1]);
	pipe(this->fd);
	while (!string().equals(str, end) && free_ob(str))
	{
		str = readline("> ");
		if (!str)
			break ;
		if (!string().equals(str, end))
		{
			write(this->fd[1], str, string().size(str));
			write(this->fd[1], "\n", 1);
		}
	}
	close(this->fd[1]);
	free_ob(str);
}

static int	*ft_input(t_command *previou, t_command *this)
{
	if (string().size_list(this->commands) >= 2 && \
	is_sep(this->commands[1]) == NO_SEP && !this->status)
	{
		heredoc(this, this->commands[1]);
		if (string().size_list(this->commands) >= 3)
			return (cread_cmd(previou, this, cread_new_arg(this->commands)));
		else
		{
			close(this->fd[0]);
			pipe(this->fd);
			close(this->fd[1]);
		}
	}
	else
		this->status = 258;
	return (terminal()->next_command(previou, this));
}

t_command	*new_left_shift(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	c->status = 0;
	c->is_real = 0;
	c->pid = 0;
	return (c);
}
