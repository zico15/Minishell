/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:03:52 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 17:58:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	gotoxy(int x)
{	
	printf("\033[%dC", x);
}

void	kill_all(t_element *e, void *o)
{
	t_command	*c;

	c = e->value;
	(void) o;
	kill(c->pid, SIGKILL);
}

static void	server_list(int signo)
{
	if (signo == SIGINT && !terminal()->cmds)
	{
		write(0, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signo == SIGQUIT && !terminal()->cmds)
	{
		gotoxy(string().size(rl_line_buffer) + 10);
	}
}

void	init_keys(void)
{
	signal(SIGQUIT, server_list);
	signal(SIGINT, server_list);
	signal(SIGUSR1, ft_read_signal);
	signal(SIGUSR2, ft_read_signal);
}
