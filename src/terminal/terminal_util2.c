/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:55:13 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 12:59:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
#include <ft_string.h>
#include <string.h>
#include <errno.h>

int	*__next_command(t_command *previou, t_command *this)
{
	if (this && this->next && this->next->input)
	{
		terminal()->check_command_args(this->next);
		if (!this->next->next || this->next->is_print)
		{
			close(this->next->fd[1]);
			this->next->fd[1] = dup(1);
		}
		this->next->input(this, this->next);
	}
	if (previou)
	{
		close(previou->fd[0]);
		close(previou->fd[1]);
	}
	return (this->fd);
}
