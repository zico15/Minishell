/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 17:34:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static void	print_echo(char *str)
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
			printf("%c", str[i]);
			is_barra = 0;
			is_barra_end = 1;
		//}
	}
	printf("%c", ' ');
}

static int	*ft_input(t_command *previou, t_command *this)
{
	int		is_line;
	int		i;
	char	*str;

	is_line = 1;
	i = 0;
	while (this->commands && *this->commands && this->commands[++i])
	{
		str = this->commands[i];
		if (i == 1 && string().contains(str, "-n") && string().size(str) == 2)
			is_line = 0;
		else
			print_echo(str);
	}
	if (is_line)
		printf("\n");
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
