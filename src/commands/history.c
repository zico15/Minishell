/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 21:00:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	write_history_all(int fd)
{
	int		len;
	char	*index;
	int		i;

	i = -1;
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
}

static int	*ft_input(t_command *previou, t_command *this)
{
	if (!this->status)
	{
		if (string().equals(this->commands[1], "-c"))
		{
			rl_clear_history();
			array(terminal()->history)->destroy();
			terminal()->history = new_array();
		}
		else
			write_history_all(this->fd[1]);
	}
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_history(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	c->is_real = 0;
	return (c);
}
