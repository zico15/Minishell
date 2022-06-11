/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/11 18:29:24 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	buff[BUFFER_SIZE];
	char	*str;

	if (this->commands && *this->commands)
	{
		str = this->commands[1];
		if (str == NULL)
			str = "/";
		if (chdir(str) != 0)
			print_msg_error(this, __COMMAND_NOT_FILE__, 2);
		str = string().copy(getcwd(buff, BUFFER_SIZE));
		hashmap(terminal()->envp)->put(string().copy("PWD"), str);
	}

	close(this->fd[1]);
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_cd(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
