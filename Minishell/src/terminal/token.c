/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:08:29 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 21:07:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

/**
 * @brief cria uma lista de argumentos
 * 		  teste > out
 * @param line 
 * @return ** char** 
 */
char	**token(char *line)
{
	char		**tokens;
	int			size;

	(void) line;
	size = 3;
	tokens = malloc(sizeof(char *) * size);
	tokens[0] = string().copy("ls -la");
	tokens[1] = string().copy("< out.txt");
	tokens[2] = string().copy("wc");
	//tokens[3] = string().copy("> out2.txt");
	tokens[size - 1] = 0;
	//printf("teste: (%s)\n", tokens[0]);
	/*tokens = string().split(line, '"');
	if (tokens && *tokens)
	{
	
	}
	else
	{
		free_list(tokens);
		tokens = string().split(line, ' ');
	}*/
	return (tokens);
}
