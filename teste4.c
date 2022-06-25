/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:51:45 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 12:05:33 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ft_util.h>
#include <ft_string.h>
#include <ft_token.h>

int	main4(void)
{
	char		*str = "asdads   asdads";
	t_command	c;
	
	(void) c;
	str = string().copy(str);
	printf("sizeof: %i\n", sizeof(*str) == sizeof(void *));
	return (0);
}
