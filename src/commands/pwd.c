/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 12:35:47 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	buff[BUFFER_SIZE];
	char	*str;
	int		fd;

	fd = this->fd[1];
	if (!this->next || this->is_print)
		fd = 1;
	str = getcwd(buff, BUFFER_SIZE);
	write(fd, str, string().size(str));
	write(fd, "\n", 1);
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_pwd(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
