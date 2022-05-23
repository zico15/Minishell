/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 16:29:06 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

void		cread_outinput(t_command *previou, t_command *this, char *str);
static void	print_input_end(t_command *this, char *str);

static int	*input(t_command *previou, t_command *this)
{
	char	str[BUFFER_SIZE];
	int		ft_open;

	pipe(this->fd);
	str[0] = 0;
	(void) previou;
	ft_open = open(this->commands[1], O_RDONLY);
	if (ft_open >= 0)
		str[read(ft_open, str, BUFFER_SIZE)] = 0;
	close(ft_open);
	cread_outinput(previou, this, str);
	next_command(previou, this);
	return (this->fd);
}

void	cread_outinput(t_command *previou, t_command *this, char *str)
{
	char	buffer[BUFFER_SIZE];
	int		size_buff;
	int		size_str;

	size_str = string().size(str);
	if (previou->index >= 0 && previou->fd[0] >= 0 && previou->fd[1] >= 0)
	{
		dup2(previou->fd[1], 1);
		close(previou->fd[1]);
		size_buff = read(previou->fd[0], buffer, BUFFER_SIZE);
		close(previou->fd[0]);
		buffer[size_buff] = 0;
		write(this->fd[1], buffer, size_buff);
		write(this->fd[1], str, size_str);
		write(this->fd[1], "\0", 1);
	}
	else
		print_input_end(this, str);
}

static void	print_input_end(t_command *this, char *str)
{
	char	buffer[1];

	close(this->fd[0]);
	close(this->fd[1]);
	this->fd[0] = -1;
	this->fd[1] = -1;
	printf("%s\n", str);
	printf("(END)\n");
	read(0, buffer, 1);
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
