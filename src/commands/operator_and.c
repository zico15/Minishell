/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/12 21:03:13 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	close(this->fd[1]);
	if (previou->pid)
		waitpid(previou->pid, &(previou->status), 0);
	previou->status = WEXITSTATUS(previou->status);
	if (previou->status)
		(terminal())->print_error(previou, previou->status);
	terminal()->status_exit = previou->status;
	if (!previou->status)
		next_command(previou, this);
	return (this->fd);
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
			this->is_print = 1;
}
