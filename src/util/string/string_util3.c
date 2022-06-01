/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:38:15 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 11:05:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>
#include <string_util.h>
#include <stdio.h>
#include <ft_util.h>

static char	*convert_base(char *str, int n, char *base, int size_base)
{
	if (n <= -10 || n >= 10)
		str = convert_base(str, (n / size_base), base, size_base);
	*str++ = base[(n % size_base) * ((n > 0) - (n < 0))];
	*str = 0;
	return (str);
}

int	__isalnum(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') \
	|| (c >= '0' && c <= '9'));
}

char	**__split_spacer(char const *str1, char *spacer)
{
	return (__split(str1, spacer, 0, 0));
}

char	*__itoa(int n)
{
	char	buff[BUFFER_SIZE];

	buff[0] = '-';
	convert_base(buff + (n < 0), n, "0123456789", 10);
	return (string().copy(buff));
}
