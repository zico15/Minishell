/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/20 16:43:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char	*temp;
	int		i;

	i = 0;
	while (this->commands && this->commands[++i])
	{
		temp = this->commands[i];
		(hashmap(terminal()->envp))->remove_key(temp);
	}
	close(this->fd[1]);
	terminal()->update_env();
	return (terminal()->next_command(previou, this));
}

t_command	*new_unset(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}

void	unset_remove(t_terminal	*t, char *str)
{
	char		**list;
	int			i;

	i = 0;
	if (!t || !str || !*str)
		return ;
	list = string().split(str, " ");
	if (!list || !string().equals(*list, "unset"))
	{
		free_list(list);
		return ;
	}
	while (list && list[++i])
	{
		(hashmap(t->envp))->remove_key(list[i]);
	}
	terminal()->update_env();
	ft_send_msg(terminal()->pid_parent, str);
	free_ob(list);
}
