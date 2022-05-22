/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 22:58:30 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

static int	*input(int fd[2])
{
	char	buffer[BUFFER_SIZE];
	int		fd_open;
	int		size;

	dup2(fd[1], 1);
	close(fd[1]);
	size = read(fd[0], buffer, BUFFER_SIZE);
	buffer[size] = 0;
	close(fd[0]);
	fd_open = open(this()->list->this->commands[1], \
	O_CREAT | O_WRONLY, S_IRWXO);
	if (fd_open >= 0)
		write(fd_open, buffer, size);
	if (this()->list && this()->list->this)
		this()->list->this = this()->list->this->next;
	return (fd);
}

static int	ft_execute(t_command *cmd, int input, int out)
{
	(void) cmd;
	(void) input;
	(void) out;
	return (1);
}

t_command	*new_redirect_output(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = input;
	c->execute = ft_execute;
	return (c);
}
