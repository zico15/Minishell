/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 18:55:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	buff[BUFFER_SIZE];
	char	*str;

	str = getcwd(buff, BUFFER_SIZE);
	write(this->fd[1], str, string().size(str));
	write(this->fd[1], "\n", 1);
	close(this->fd[1]);
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_pwd(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
