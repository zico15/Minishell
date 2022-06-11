/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/11 17:51:13 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	int		i;
	int		len;
	char	*index;
	int		fd;

	i = -1;
	fd = this->fd[1];
	if (!this->next || this->is_print)
		fd = 1;
	if (string().equals(this->commands[1], "-c"))
	{
		rl_clear_history();
		array(terminal()->history)->destroy();
		terminal()->history = new_array();
	}
	while (++i < array(terminal()->history)->size)
	{
		len = string().size(array(terminal()->history)->get(i));
		index = string().itoa(i + 1);
		write(fd, "    ", 4);
		write(fd, index, string().size(index));
		write(fd, "  ", 2);
		write(fd, array(terminal()->history)->get(i), len);
		write(fd, "\n", 1);
		free_ob(index);
	}
	close(this->fd[1]);
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_history(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
