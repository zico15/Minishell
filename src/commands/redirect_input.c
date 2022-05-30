/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2022/05/26 22:38:33 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_pipex.h>

static int	*input(t_command *previou, t_command *this)
{
	int		fd_open;
	char	*str;

	if (pipe(this->fd) == __PIPE_ERROR__)
		return (0);
	str = NULL;
	fd_open = open(this->commands[1], O_RDONLY);
	if (fd_open >= 0)
	{
		str = read_all(fd_open);
		write(this->fd[1], str, string().size(str));
		close(fd_open);
	}
	else if (fd_open < 0 && this->commands && *this->commands)
		print_msg_error(this, __COMMAND_NOT_FILE__, 2);
	//printf("teste: %s\n", str);
	next_command(previou, this);
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}

t_command	*new_redirect_input(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = input;
	return (c);
}
