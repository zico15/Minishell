/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 19:06:15 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

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
		this->next->is_real = 0;
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
	c->is_real = 0;
	return (c);
}

void	check_operator_and(t_command *this)
{
	if (this->next && this->next->commands && \
	string().equals(*this->next->commands, "&&"))
	{
		close(this->fd[1]);
		this->fd[1] = dup(1);
		this->is_real = 0;
	}
}
