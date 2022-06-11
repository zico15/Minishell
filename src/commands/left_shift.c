/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/11 20:41:09 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static char	*ft_readline(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*str;
	char	*mem;
	int		size;

	size = 0;
	str = NULL;
	buff[0] = 0;
	while (!str || buff[0] != '\n')
	{
		size += read(fd, buff, 1);
		buff[1] = 0;
		mem = str;
		if (buff[0] != '\n')
			str = string().join(str, buff);
		free_ob(mem);
	}
	return (str);
}

static int	*ft_input(t_command *previou, t_command *this)
{
	int		fd;
	char	*div;
	char	*str;
	char	*buff;
	char	*mem;

	fd = this->fd[1];
	if (!this->next || this->is_print)
		fd = 1;
	div = this->commands[1];
	if (div)
	{
		str = NULL;
		buff = NULL;
		while (1)
		{
			write(0, "> ", 2);
			str = ft_readline(0);
			if (!string().equals(str, div))
			{
				mem = string().join(buff, "\n");
				free_ob(buff);
				buff = mem;
				mem = string().join(buff, str);
				free_ob(buff);
				free_ob(str);
				buff = mem;
			}
			else
				break ;
		}
		free_ob(str);
		printf("%s\n", buff);
		free_ob(buff);
	}
	close(this->fd[1]);
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_left_shift(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
