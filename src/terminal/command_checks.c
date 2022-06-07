/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:58:46 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/07 20:25:01 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

char	*check_wildcards(char *str)
{
	char		*paths;
	char		*exts;
	char		*result;

	result = str;
	if (string().size(str) > 1 && string().contains(str, "*"))
	{
		paths = terminal()->wildcards(str);
		if (paths)
		{
			exts = terminal()->get_exts(str);
			result = string().replace(str, paths, exts);
			free_ob(str);
		}
	}
	return (result);
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
	int	i;

	i = 0;
	if (!this)
		return ;
	while (this->commands[++i])
		this->commands[i] = check_wildcards(this->commands[i]);
	i = -1;
	if (!this->path[0] && !access(this->commands[0], F_OK) && this->commands)
	{
		while (this->commands[0] && this->commands[0][++i])
			this->path[i] = this->commands[0][i];
		this->path[i] = 0;
	}
}
