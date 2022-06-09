/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:02:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/09 16:03:41 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*input(t_command *previou, t_command *this)
{
	int		fd_open;
	char	*str;

	str = NULL;
	fd_open = open(this->commands[1], O_RDONLY);
	if (fd_open >= 0)
	{
		str = read_all(fd_open);
		write(this->fd[1], str, string().size(str));
		close(this->fd[1]);
		close(fd_open);
	}
	else if (fd_open < 0 && this->commands && *this->commands)
		print_msg_error(this, __COMMAND_NOT_FILE__, 2);
	next_command(previou, this);
	return (this->fd);
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
