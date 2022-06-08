/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:44:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/08 22:47:09 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static t_command	*ft_add(t_command *cmd)
{
	if (this()->list && cmd)
	{
		if (this()->list->beging == NULL)
		{
			cmd->index = 0;
			this()->list->beging = cmd;
			this()->list->end = cmd;
		}
		else
		{
			cmd->index = this()->list->end->index + 1;
			this()->list->end->next = cmd;
			this()->list->end = cmd;
		}
		cmd->next = NULL;
		this()->list->this = cmd;
	}
	return (cmd);
}

static void	ft_for_each(void (*fun)(t_command **cmd))
{
	t_command	*temp;
	int			i;

	if (!this() || !this()->list)
		return ;
	i = 0;
	temp = this()->list->beging;
	while (temp)
	{
		this()->list->this = temp;
		temp = temp->next;
		fun(&this()->list->this);
		if (i == 0)
			this()->list->beging = this()->list->this;
	}
}

static t_command	*ft_get(int index)
{
	t_command	*temp;
	int			i;

	if (!this() || !this()->list)
		return (NULL);
	i = 0;
	temp = this()->list->beging;
	while (temp)
	{
		this()->list->this = temp;
		if (i == index)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

void	*new_list(void)
{
	t_list_cmd	*list;

	list = malloc_ob(sizeof(t_list_cmd) * 1);
	if (!list)
	{
		printf("err: %s\n", "malloc_ob");
		return (0);
	}
	list->forEach = ft_for_each;
	list->get = ft_get;
	list->beging = NULL;
	list->end = NULL;
	list->this = NULL;
	list->add = ft_add;
	this()->list = list;
	return (list);
}
