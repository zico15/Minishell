/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:00:10 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 13:38:18 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <dirent.h>

static int	equals_extension(const char *dir_name, const char *exts)
{
	int	size;

	if (string().equals(exts, "*"))
		return (1);
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

char	*__get_exts(const char *str)
{
	int		i;
	char	*v;

	i = string().contains(str, "*");
	v = NULL;
	printf("teste1: (%i)\n", i);
	if (!str && i <= 0)
		return (NULL);
	str += i;
	i = 0;
	printf("teste2: (%s)\n", str);
	while (str[i] && (string().isalnum(str[i]) || str[i] == '_'))
		i++;
	v = string().copy_n(str, i);
	return (v);
}

char	*__wildcards(const char *exts)
{
	DIR					*dir;
	char				*paths;

	if (!exts)
		return (NULL);
	dir = opendir(".");
	paths = NULL;
	if (!dir || !ft_execute(dir, readdir(dir), (char *)exts, &paths))
		paths = NULL;
	closedir(dir);
	return (paths);
}
