/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/23 16:57:08 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

char **token(char *line)
{
	(void) line;
	void *tokens;

	tokens = new_array();
	array(tokens)->add("sddf");
	return (NULL);
}

// array(tokens)->add("sddf");
// array(tokens)->add("ass");
// int i = -1;
// while (++i < array(tokens)->size)
// {
// 	printf("%s\n",  array(tokens)->get(i));
// }
