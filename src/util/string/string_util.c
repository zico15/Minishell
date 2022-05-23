/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 18:25:14 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*__join(const char *str1, const char *str2)
{
	char	*str;
	int		i;

	str = malloc(string().size((char *) str1) \
	+ string().size((char *) str2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (str1 && *str1)
		str[i++] = *str1++;
	while (str2 && *str2)
		str[i++] = *str2++;
	str[i] = 0;
	return (str);
}

/***
 * separador c or \n
 * ***/
char	**__split(char const *s, char c, int j, char **list)
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
		list = __split(s, c, j, list);
	else if (!list)
		list = malloc(j * sizeof(char *));
	if (list)
		list[--j] = str;
	return (list);
}


/*
copys n characters of string 
*/
char	*__copy_n(const char *str, int n)
{
	char	*copy;
	int		i;

	if (!str)
		return (NULL);
	i = -1;
	copy = malloc(n + 1);
	while (copy && str[++i] && i < n)
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
}
