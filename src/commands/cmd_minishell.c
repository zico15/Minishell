/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_minishell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/04 11:11:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	printf("===========minishell===========\n");
	printf("pid: %i\n", terminal()->pid);
	printf("pid parent: %i\n", terminal()->pid_parent);
	printf \
	("created by: (amaria-m) António Maria Mouro Ferreira Abranches Pinto\n");
	printf("created by: (edos-san) Ezequiel Carlos Dos Santos\n");
	printf("===========================\n");
	close(this->fd[1]);
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_minishell(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
