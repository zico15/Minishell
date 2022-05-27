/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/27 14:30:09 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>

static int	ft_size(const char *s)
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
static char	**ft_split(const char *s, char c)
{
	return (__split(s, c, 0, 0));
}

char	*ft_copy(const char *str)
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

static int	ft_contains(const char *str, const char *hey)
{
	int	i;
	int	j;
	int	co;

	i = -1;
	co = 0;
	while (str && str[++i] && !co)
	{
		j = 0;
		while (!co && hey && hey[j] && str[i + j] && hey[j] == str[i + j])
		{
			j++;
			if (!hey[j] || !str[i + j])
				co = !hey[j];
		}
	}
	return (co);
}

t_string	string(void)
{
	static t_string	str = {
		ft_contains, ft_split, ft_size, ft_copy, __join, __copy_n, __str_trim,
		__equals, __equals_n, __is_space
	};

	return (str);
}
