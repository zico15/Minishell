/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:51:45 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 20:00:21 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ft_util.h>
#include <ft_string.h>

int	main(void)
{
	char	*code;

	code = create_code_nivel_priority(2);
	printf("code: (%s) len: %i\n", code, string().size(code));
	check_nivel_priority_teste(code);
	free(code);
	return (0);
}
