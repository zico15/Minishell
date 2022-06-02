/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:16:56 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 18:43:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <ft_pipex.h>


void	ft_read_signal(int signal)
{
	static char	letter;
	static int	bit;
	static char	buff[BUFFER_SIZE];
	static int	index;

	if (signal == SIGUSR2)
		letter |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		buff[index++] = letter;
		if (letter == 0 && terminal() && terminal()->sigaction)
		{
			terminal()->sigaction(buff);
			index = 0;
		}
		letter = 0;
		bit = 0;
	}
}

static void	ft_send_char(int pid_t, char a)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (a & (1 << bit))
			kill(pid_t, SIGUSR2);
		else
			kill(pid_t, SIGUSR1);
		usleep(1000);
		bit++;
	}
}

void	ft_send_msg(int pid_t, const char *msg)
{
	if (!msg || pid_t == -1)
		return ;
	while (*msg)
		ft_send_char(pid_t, *msg++);
	ft_send_char(pid_t, 0);
}
