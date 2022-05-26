/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 16:29:06 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*input(t_command *previou, t_command *this)
{
	char	buffer[BUFFER_SIZE];
	int		fd_open;
	int		size;

	dup2(previou->fd[1], 1);
	close(previou->fd[1]);
	size = read(previou->fd[0], buffer, BUFFER_SIZE);
	buffer[size] = 0;
	close(previou->fd[0]);
	fd_open = open(this->commands[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_open >= 0)
		write(fd_open, buffer, size);
	next_command(previou, this);
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
