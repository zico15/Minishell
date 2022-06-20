/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:03:14 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/20 17:37:46 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	redirect(int fd, t_command *previou, t_command *this)
{
	char	*str;

	if (fd < 0)
	{
		this->status = 1;
		return ;
	}
	str = read_all(previou->fd[0]);
	write(previou->fd[0], "", 1);
	close(previou->fd[0]);
	if (fd >= 0 && str)
		write(fd, str, string().size(str));
	free_ob(str);
	close(fd);
}

static int	*input(t_command *previou, t_command *this)
{
	int		fd_open;

	if (string().size_list(this->commands) <= 1 || \
	is_sep(this->commands[1]) != NO_SEP)
	{
		if (previou->pid)
			kill(previou->pid, SIGTERM);
		this->status = 258;
	}
	if (!this->status && previou->index != __COMMAND_BEGING_ && \
	string().size_list(this->commands) > 1)
	{
		fd_open = open(this->commands[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (this->next && (string().equals(*this->next->commands, ">") \
		|| string().equals(*this->next->commands, ">>")))
		{
			close(fd_open);
			fd_open = this->fd[1];
		}
		redirect(fd_open, previou, this);
	}
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_redirect_output(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = input;
	return (c);
}
