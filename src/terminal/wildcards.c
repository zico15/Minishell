/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:00:10 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/28 17:20:46 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <dirent.h>

static int	equals_extension(const char *dir_name, const char *exts)
{
	int	size;

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

char	*__wildcards(char *exts)
{
	DIR					*dir;
	char				*paths;

	if (!exts)
		return (NULL);
	dir = opendir(".");
	paths = NULL;
	if (!dir || !ft_execute(dir, readdir(dir), exts, &paths))
		paths = string().copy(exts);
	closedir(dir);
	return (paths);
}
