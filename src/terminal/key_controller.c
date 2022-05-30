/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:03:52 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/24 21:52:44 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static void	server_list(int signo, siginfo_t *i, void *context)
{
	(void) context;
	(void) i;
	if (SIGQUIT == signo)
	{
		//rl_replace_line();
	}
	if (signo == SIGINT)
	{
		printf("\r");
		exit(0);
	}
}

void	init_keys(void)
{
	struct sigaction	usr_action;

	usr_action.sa_flags = SA_SIGINFO;
	usr_action.sa_sigaction = server_list;
    sigaction(SIGQUIT, &usr_action, NULL);
	sigaction(SIGINT, &usr_action, NULL);
}
