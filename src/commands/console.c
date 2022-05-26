/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/26 20:17:55 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	buffer[BUFFER_SIZE];
	char	*str;

	dup2(previou->fd[1], 1);
	close(previou->fd[1]);
	buffer[read(previou->fd[0], buffer, BUFFER_SIZE)] = 0;
	printf("%s", buffer);
	str = read_all(previou->fd[0]);
	if (str)
		printf("%s", str);
	free_ob(str);
	close(previou->fd[0]);
	if (!next_command(previou, this))
	if (0 && !next_command(previou, this))
		return (this->destroy(this));
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}

t_command	*new_console(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
