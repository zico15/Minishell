/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:08:29 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/23 11:29:06 by amaria-m         ###   ########.fr       */
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
	int		i;
	int		j;
	int		word;
	char	**cmds;
	char	**tokens;

	cmds = string().split(line, ' ');
	i = 0;
	word = 0;
	while (cmds && cmds[i])
	{
		if (word && cmds[i][0] == '-')
			tokens[j] = string().join(cmds[i - 1], cmds[i]);

		i++;
	}
	


	return (tokens);
}

/*char	**token(char *line)
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
*/