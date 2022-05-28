/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/28 17:36:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

int ft_read_dollar(char *str, int index)
{
	(void) str;
	(void) index;
	return (0);
}

char    *ft_dollar(char *str)
{
	char    *cpy;
	char    *mem;

	mem = string().strnstr(str, "$", string().size(str));
	if (mem)
	{
		cpy = string().copy_n(str, mem - str);
		//printf("%s\n", cpy);
		free(cpy);
	}
	return (str);
}
