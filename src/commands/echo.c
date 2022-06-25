/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 20:59:37 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	print_echo(int fd, char *str)
{
	int	i;
	int	is_barra;

	i = -1;
	is_barra = 0;
	while (str && str[++i])
	{
		if (!is_barra && str[i] == '\\')
			is_barra = 1;
		else
			write(fd, &str[i], 1);
		is_barra = 0;
	}
}

static int	*ft_input(t_command *previou, t_command *this)
{
	int		is_line;
	int		i;
	char	*str;

	is_line = 1;
	i = 1;
	if (!this->status)
	{
		while (this->commands && *this->commands && this->commands[i])
		{
			str = this->commands[i];
			if (i == 1 && string().contains(str, "-n") && \
			string().size(str) == 2)
				is_line = 0;
			else
				print_echo(this->fd[1], str);
			if (this->commands[++i] && !(is_line == 0 && i == 2))
				write(this->fd[1], " ", 1);
		}
		if (is_line)
			write(this->fd[1], "\n", 1);
	}
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_echo(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	c->is_real = 0;
	return (c);
}
