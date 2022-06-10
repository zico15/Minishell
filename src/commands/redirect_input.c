/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:02:54 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/10 18:11:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*input(t_command *previou, t_command *this)
{
	int		fd_open;
	char	buff[BUFFER_SIZE];
	int		i;

	fd_open = 0;
	printf("redirect_input\n");
	if (string().size_list(this->commands) >= 3)
	{
		fd_open = open(this->commands[1], O_RDONLY);
		i = read(fd_open, buff, BUFFER_SIZE);
		buff[i] = 0;
		write(this->fd[1], buff, i);
		close(fd_open);
	}
	close(this->fd[1]);
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
