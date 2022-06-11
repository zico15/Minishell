/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:58:46 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/11 19:32:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

void	check_wildcards(char *str, void *arg, int index)
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

static char	*replace_dolar(char *str, void *env, char *dollar, char *key)
{
	char		*value;
	char		*new;
	t_element	*e;

	value = "";
	e = hashmap(env)->get_key(key);
	if (e)
		value = e->value;
	new = string().replace(str, value, dollar);
	free_ob(str);
	return (new);
}

char	*check_dolar(void *env, const char *line, int i, int size)
{
	char	buff[BUFFER_SIZE];
	char	*new;
	int		j;

	if (!line)
		return (NULL);
	if (!*line)
		return (string().copy(line));
	j = -1;
	new = string().trim(line);
	while (line && i <= size)
	{
		if (j >= 0 && (string().is_space(line[i]) || \
		line[i] == '$' || !line[i] || !string().isalnum(line[i])))
		{
			buff[j] = 0;
			j = -1;
			new = replace_dolar(new, env, buff, &buff[1]);
		}
		else if (j >= 0)
			buff[j++] = line[i];
		if (j == -1 && line[i] == '$' && is_quotes(line, i) != SINGLE_QUOTED \
		&& ++j > -1)
			buff[j++] = line[i];
		i++;
	}
	return (new);
}

void	__check_args(t_command *this)
{
	int		i;
	void	*arg;

	i = -1;
	if (!this)
		return ;
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
