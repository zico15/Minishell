/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 22:20:19 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_string.h"

static int	ft_size(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/***
 * separador c or \n
 * ***/
static char	**ft_split(char const *s, char c, int j, char **list)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	while (s && (*s == c || *s == '\n') && *s)
		s++;
	while (s && (*s != c && *s != '\n') && s[i])
		i++;
	if (i > 0)
		str = malloc((i + 1) * sizeof(char));
	if (i > 0)
		str[i] = 0;
	i = 0;
	while (s && str && s && (*s != c && *s != '\n') && *s)
		str[i++] = *s++;
	if (++j >= 0 && i)
		list = ft_split(s, c, j, list);
	else if (!list)
		list = malloc(j * sizeof(char *));
	if (list)
		list[--j] = str;
	return (list);
}

char	*ft_copy(char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (str);
	i = -1;
	copy = malloc(ft_size(str));
	while (copy && str[++i])
		copy[i] = str[i];
	return (copy);
}

static int	ft_contains(char *str, char *hey)
{
	int	i;

	i = 0;
	while (str && hey && hey[i] && str[i] && hey[i] == str[i])
	{
		i++;
		if (!hey[i] || !str[i])
			return (!hey[i]);
	}
	return (0);
}

t_string	string(void)
{
	static t_string	str = {
		ft_contains, ft_split, ft_size, ft_copy
	};

	return (str);
}
