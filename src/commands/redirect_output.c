/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2022/05/26 22:10:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include <ft_pipex.h>

static int	*input(t_command *previou, t_command *this)
{
	char	*str;
	int		fd_open;

	dup2(previou->fd[1], 1);
	close(previou->fd[1]);
	if (pipe(this->fd) == __PIPE_ERROR__)
		return (0);
	if (previou->index != __COMMAND_BEGING_)
	{
		str = read_all(previou->fd[0]);
		close(previou->fd[0]);
		fd_open = open(this->commands[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_open >= 0 && str)
			write(fd_open, str, string().size(str));
		free_ob(str);
		close(fd_open);
	}
	next_command(previou, this);
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}

t_command	*new_redirect_output(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = input;
	return (c);
}
