/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 18:01:18 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/ft_string.h"
#include "string_util.h"
#include <stdio.h>

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
static char	**ft_split(char const *s, char c)
{
	return (__split(s, c, 0, 0));
}

char	*ft_copy(char *str)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	copy = malloc(ft_size(str) + 1);
	while (copy && str[++i])
		copy[i] = str[i];
	copy[i] = 0;
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
	printf("ft_contains: (%s) / (%s)\n", str, hey);
	return (0);
}

t_string	string(void)
{
	static t_string	str = {
		ft_contains, ft_split, ft_size, ft_copy, __join
	};

	return (str);
}
