/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/23 17:29:00 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

char	**token(char *line)
{
	int		i;
	char	**cmds;
	int		word;
	void *tokens;

	cmds = string().split(line, ' ');
	tokens = new_array();
	word = 0;
	i = 0;
	while (cmds && cmds[i])
	{
		if ()
		// array(tokens)->add(cmds[i++]);
	}
	return (NULL);
}

// array(tokens)->add("sddf");
// array(tokens)->add("ass");
// int i = -1;
// while (++i < array(tokens)->size)
// {
// 	printf("%s\n",  array(tokens)->get(i));
// }
