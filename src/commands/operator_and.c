/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/23 18:04:09 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
/*
static int	*ft_input(t_command *previou, t_command *this)
{
	close(this->fd[1]);
	if (previou->pid)
	{
		waitpid(previou->pid, &(previou->status), 0);
		previou->status = WEXITSTATUS(previou->status);
	}
	if (previou->status && !previou->pid)
		(terminal())->print_error(previou, previou->status);
	terminal()->status_exit = previou->status;
	if (!previou->status)
		return (terminal()->next_command(previou, this));
	return (this->fd);
}*/

static int	*ft_input(t_command *previou, t_command *this)
{
	close(this->fd[1]);
	if (previou->pid)
	{
		waitpid(previou->pid, &(previou->status), 0);
		previou->status = WEXITSTATUS(previou->status);
	}
	if (previou->status && (!previou->pid || previou->status == 127))
		(terminal())->print_error(previou, previou->status);
	if (previou->status && this->next)
	{
		this->next->is_user = 0;
		if (this->next->next && \
		string().equals(*this->next->next->commands, "||"))
			return (terminal()->next_command(previou, this->next));
		return (this->fd);
	}
	return (terminal()->next_command(previou, this));
}

t_command	*new_operator_and(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}

void	check_operator_and(t_command *this)
{
	if (this->next && this->next->commands && \
	string().equals(*this->next->commands, "&&"))
	{
		close(this->fd[1]);
		this->fd[1] = dup(1);
		this->is_user = 0;
	}
}
