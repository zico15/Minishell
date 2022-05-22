/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:08:29 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 22:33:57 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

char	**token(char *line)
{
	char		**tokens;

	tokens = string().split(line, '"', 0, 0);
	if (tokens && *tokens)
	{

	}
	else
	{
		free_list(tokens);
		tokens = string().split(line, ' ', 0, 0);
	}
	return (tokens);
}
