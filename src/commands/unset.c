/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 18:54:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	*temp;

	if (string().size_list(this->commands) > 1)
	{
		temp = this->commands[1];
		(hashmap(terminal()->envp))->remove_key(temp);
		if (temp && terminal()->pid_parent != -1)
		{
			temp = string().join("unset ", temp);
			ft_send_msg(terminal()->pid_parent, temp);
		}
	}
	close(this->fd[1]);
	terminal()->update_env();
	next_command(previou, this);
	return (this->fd);
}

t_command	*new_unset(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}

void	unset_remove(t_terminal	*t, char *str)
{
	char		**list;

	if (!t || !str || !*str)
		return ;
	list = string().split(str, " ");
	if (!list || !string().equals(*list, "unset"))
	{
		free_list(list);
		return ;
	}
	if (string().size_list(list) > 1)
	{
		(hashmap(t->envp))->remove_key(list[1]);
	}
	terminal()->update_env();
	ft_send_msg(terminal()->pid_parent, str);
	free_ob(list);
}
