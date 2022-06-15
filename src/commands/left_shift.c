/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 12:35:47 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	*div;
	char	*str;

	div = NULL;
	str = NULL;
	if (string().size_list(this->commands) > 1)
		div = this->commands[1];
	else
		this->status = 258;
	while (div)
	{
		write(2, "> ", 2);
		str = get_next_line(0);
		if (!string().equals_n(str, div, string().size(div)) && str)
			write(this->fd[1], str, string().size(str));
		else
			break ;
		free_ob(str);
		str = NULL;
	}
	free_ob(str);
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_left_shift(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	c->status = 0;
	c->pid = 0;
	return (c);
}
