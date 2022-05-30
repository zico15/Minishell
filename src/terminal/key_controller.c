/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:03:52 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 18:06:13 by edos-san         ###   ########.fr       */
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
	if (SIGUSR1 == signo)
	{
		terminal()->is_erro_cmd = 1;
		printf("SIGUSR1\n");
	}
}

void	init_keys(void)
{
	struct sigaction	usr_action;

	getpid();
	usr_action.sa_flags = SA_SIGINFO;
	usr_action.sa_sigaction = server_list;
    sigaction(SIGQUIT, &usr_action, NULL);
	sigaction(SIGINT, &usr_action, NULL);
	sigaction(SIGUSR1, &usr_action, NULL);
}
