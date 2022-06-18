/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 13:21:51 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/18 17:34:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static char	*replace_dolar(char *str, void *env, char *dollar, char *key)
{
	char		*value;
	char		*new;
	t_element	*e;

	value = "";
	if (!key || !*key)
		return (str);
	else if (string().equals(key, "?"))
		value = string().itoa(terminal()->status_exit);
	else
	{
		e = hashmap(env)->get_key(key);
		if (e)
			value = e->value;
	}
	new = string().replace(str, value, dollar);
	//free_ob(str);
	if (string().equals(key, "?"))
		free_ob(value);
	return (new);
}

static int	is_valid(const char *str, int i, int j)
{
	if (str[i] == '_' || (str[i] == '?' && j == 1))
		return (1);
	if (str[i] == '_')
		return (1);
	if (string().is_space(str[i]) || str[i] == '$' || !str[i])
		return (0);
	if (!string().isalnum(str[i]))
		return (0);
	if (i > 0 && string().isnumber(_str(str[i - 1])))
		return (0);
	if (i > 0 && j > 1 && str[i - 1] == '?' )
		return (0);
	return (1);
}

char	*cread_new_str(char *new, int i, void *env, char	*buff)
{
	char	*temp1;
	char	*temp2;
	char	*result;

	temp1 = string().copy_n(new, i);
	temp2 = replace_dolar((new + i), env, buff, &buff[1]);
	result = string().join(temp1, temp2);
	free_ob(temp1);
	free_ob(temp2);
	free_ob(new);
	return (result);
}

char	*check_dolar(void *env, const char *line, int i, int size)
{
	char	buff[BUFFER_SIZE];
	char	*new;
	int		j;

	j = -1;
	new = string().trim(line);
	while (line && i <= size)
	{
		if (j >= 0 && !is_valid(line, i, j))
		{
			buff[j] = 0;
			new = cread_new_str(new, (i - j), env, buff);
			j = -1;
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
