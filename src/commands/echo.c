/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/31 21:13:47 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static void	print_echo(int fd, char *str)
{
	int	i;
	int	is_barra;
	int	is_barra_end;

	i = -1;
	is_barra = 0;
	is_barra_end = 1;
	while (str && str[++i])
	{
		/*if (!is_barra && str[i] == '\\')
			is_barra = 1;
		else if (is_barra && str[i] == '\\' && is_barra_end)
		{
			printf("%c", str[i]);
			is_barra_end = 0;
		}
		if (str[i] != '\\')
		{*/
		write(fd, &str[i], 1);
		is_barra = 0;
		is_barra_end = 1;
		//}
	}
}

static int	*ft_input(t_command *previou, t_command *this)
{
	int		is_line;
	int		i;
	char	*str;

	if (pipe(this->fd) == __PIPE_ERROR__)
		return (0);
	is_line = 1;
	i = 1;
	while (this->commands && *this->commands && this->commands[i])
	{
		str = this->commands[i];
		if (i == 1 && string().contains(str, "-n") && string().size(str) == 2)
			is_line = 0;
		else
			print_echo(this->fd[1], str);
		if (this->commands[++i])
			write(this->fd[1], " ", 1);
	}
	if (is_line)
		write(this->fd[1], "\n", 1);
	close(this->fd[1]);
	next_command(previou, this);
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}

t_command	*new_echo(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
