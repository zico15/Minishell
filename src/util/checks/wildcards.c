/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:00:10 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/12 21:03:13 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
#include <dirent.h>

static int	equals_extension(const char *dir_name, const char *exts)
{
	int	size;

	if (string().equals(exts, "*"))
		return (1);
	if (*exts == '*')
		exts++;
	size = string().size(dir_name) - 1;
	while (size >= 0 && dir_name[size] != '.')
		size--;
	if (size >= 0)
	{
		dir_name += size;
		return (string().equals(dir_name, exts));
	}
	return (0);
}

static int	ft_execute(DIR *dir, struct dirent *entiy, char *exts, char	**paths)
{
	int					is_contains;
	int					equals;
	char				*temp;

	is_contains = 0;
	while (entiy)
	{
		equals = equals_extension(entiy->d_name, exts);
		if (equals)
		{
			if (is_contains)
			{
				temp = *paths;
				*paths = string().join(temp, " ");
				free_ob(temp);
			}
			temp = *paths;
			*paths = string().join(temp, entiy->d_name);
			free_ob(temp);
		}
		is_contains += equals;
		entiy = readdir(dir);
	}
	return (is_contains);
}

/***
 * return uma string sem malloc_ob
 * ***/
char	*__get_exts(const char *str)
{
	int			i;
	static char	v[BUFFER_SIZE];

	i = string().contains(str, "*");
	v[0] = 0;
	if (!str && i <= 0)
		return (NULL);
	str += i - 1;
	i = 0;
	while (str[i] && !string().is_space(str[i]))
	{
		v[i] = str[i];
		i++;
	}
	v[i] = 0;
	return (v);
}

char	*__wildcards(const char *str)
{
	DIR					*dir;
	char				*paths;
	char				*exts;

	exts = __get_exts(str);
	if (!exts)
		return (NULL);
	dir = opendir(".");
	paths = NULL;
	if (!dir || !ft_execute(dir, readdir(dir), (char *)exts, &paths))
		paths = NULL;
	closedir(dir);
	return (paths);
}
