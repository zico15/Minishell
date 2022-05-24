/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/24 16:19:02 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	ft_separator(char l)
{
	if (l == '|' || l == '>')
		return (1);
	return (0);
}

char	**token(char *line)
{
	int		i;
	int		j;
	void	*tokens;
	char	**arr;

	tokens = new_array();
	i = 0;
	while (line[i])
	{
		j = i;
		while (line[j] && !ft_separator(line[j]))
			j++;
		if (j > i)
			array(tokens)->add(string().copy_n(line + i, j - i));
		j++;
		i = j;
	}
	arr = malloc(sizeof(char *) * (array(tokens)->size + 1));
	i = -1;
	while (++i < array(tokens)->size)
		arr[i] = string().str_trim(array(tokens)->get(i));
	arr[i] = NULL;
	array(tokens)->destroy();
	return (arr);
}

// array(tokens)->add("sddf");
// array(tokens)->add("ass");
// int i = -1;
// while (++i < array(tokens)->size)
// {
// 	printf("%s\n",  array(tokens)->get(i));
// }
