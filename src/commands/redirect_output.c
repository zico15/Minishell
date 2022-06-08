/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2022/06/06 18:37:14 by edos-san         ###   ########.fr       */
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
	if (string().size_list(this->commands) <= 1)
		printf("bash: syntax error near unexpected token `newline'\n");
	if (previou->index != __COMMAND_BEGING_ && \
	string().size_list(this->commands) > 1)
	{
		str = read_all(previou->fd[0]);
		close(previou->fd[0]);
		fd_open = open(this->commands[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_open >= 0 && str)
			write(fd_open, str, string().size(str));
		free_ob(str);
		close(fd_open);
	}
	close(this->fd[1]);
	next_command(previou, this);
	return (this->fd);
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
