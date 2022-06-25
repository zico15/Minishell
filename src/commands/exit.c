/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 20:59:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	if (!this->status && (!previou->commands || \
	string().equals(previou->commands[0], "||") || \
	string().equals(previou->commands[0], "&&")))
		terminal()->destroy("exit");
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_exit(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	c->is_real = 0;
	return (c);
}
