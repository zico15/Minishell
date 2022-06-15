/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 17:57:41 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

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
			this->status = 1;
		str = string().copy(getcwd(buff, BUFFER_SIZE));
		(hashmap(terminal()->envp))->put(string().copy("PWD"), str);
	}
	close(this->fd[1]);
	return (terminal()->next_command(previou, this));
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
