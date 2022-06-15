/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:58:46 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/12 21:03:13 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static void	check_wildcards(char *str, void *arg, int index)
{
	char		*paths;
	char		*exts;
	char		*result;
	char		**temp;

	result = str;
	temp = NULL;
	if (string().size(str) > 1 && string().equals_n(str, "*", 1))
	{
		paths = terminal()->wildcards(str);
		if (paths)
		{
			exts = terminal()->get_exts(str);
			result = string().replace(str, paths, exts);
			temp = string().split(result, " ");
			while (temp && temp[index])
				array(arg)->add(temp[index++]);
			free_ob(result);
		}
	}
	else
		array(arg)->add(result);
	free_ob(temp);
}

void	__check_args(t_command *this)
{
	int		i;
	void	*arg;

	i = -1;
	if (!this)
		return ;
	check_operator_and(this);
	check_operator_or(this);
	arg = new_array();
	while (this->commands && this->commands[++i])
		check_wildcards(this->commands[i], arg, 0);
	free_ob(this->commands);
	this->commands = array(arg)->to_str();
	array(arg)->destroy();
	i = -1;
	if (!this->path[0] && this->commands && !access(*this->commands, F_OK))
	{
		while (this->commands[0] && this->commands[0][++i])
			this->path[i] = this->commands[0][i];
		this->path[i] = 0;
	}
}
