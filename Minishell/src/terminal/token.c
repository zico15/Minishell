/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:08:29 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 17:59:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

/**
 * @brief cria uma lista de argumentos
 * 
 * @param line 
 * @return ** char** 
 */
char	**token(char *line)
{
	char		**tokens;

	(void) line;
	tokens = malloc(sizeof(char *) * 4);
	tokens[0] = string().copy("ls -la");
	tokens[1] = string().copy("wc");
	tokens[2] = string().copy("> out.txt");
	tokens[3] = 0;
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
