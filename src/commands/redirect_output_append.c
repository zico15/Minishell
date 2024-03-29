/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output_append.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:03:14 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/25 16:59:18 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	write_file(void *list, t_command *this)
{
	int		i;
	int		fd_open;
	char	*str;

	fd_open = open(this->commands[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (this->next && (string().equals(*this->next->commands, ">") \
	|| string().equals(*this->next->commands, ">>")))
	{
		close(fd_open);
		fd_open = this->fd[1];
	}
	if (fd_open < 0)
	{
		this->status = 1;
		return ;
	}
	i = -1;
	while (++i < array(list)->size)
	{
		str = array(list)->get(i);
		if (str)
			write(fd_open, str, string().size(str));
	}
	close(fd_open);
	array(list)->destroy();
}	

static int	*input(t_command *previou, t_command *this)
{
	int		fd_open;
	void	*list;

	fd_open = -1;
	if (string().size_list(this->commands) <= 1 || \
	is_sep(this->commands[1]) != NO_SEP)
		this->status = 258;
	else if (previou->index != __COMMAND_BEGING_ && \
	string().size_list(this->commands) > 1)
	{
		list = new_array();
		fd_open = open(this->commands[1], O_RDONLY);
		array(list)->add(read_all(fd_open));
		close(fd_open);
		array(list)->add(read_all(previou->fd[0]));
		close(previou->fd[0]);
		write_file(list, this);
	}
	if (fd_open != -1)
		close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_redirect_output_append(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = input;
	return (c);
}
