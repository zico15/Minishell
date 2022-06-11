/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_output_append.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:03:14 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/11 20:52:32 by edos-san         ###   ########.fr       */
/*                                                                            */
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

t_command	*new_redirect_output_append(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = input;
	return (c);
}
