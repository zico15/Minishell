/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/27 17:26:18 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

int ft_read_dollar(char *str, int index)
{
	
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