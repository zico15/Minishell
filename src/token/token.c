/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/26 20:12:00 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

char	**token(char *line)
{
	int		i;
	int		j;
	int		separator;
	void	*tokens;
	char	**arr;

	if (!line)
		return (ft_exit());
	if (!(*line))
		return (NULL);
	tokens = new_array();
	i = 0;
	separator = 0;
	while (line[i])
	{
		j = i;
		while (line[j] && (ft_quotes(&line[j]) || separator || ft_separator(line[j])))
			if (ft_separator(line[j++]))
				separator = 0;
		if (j > i)
		{
			separator = 1;
			array(tokens)->add(string().copy_n(line + i + (line[i] == '|'), j - i - (line[i] == '|')));
		}
		i = j;
	}
	arr = malloc(sizeof(char *) * (array(tokens)->size + 1));
	i = -1;
	while (++i < (array(tokens)->size + 1))
		arr[i] = string().trim(array(tokens)->get(i));
	array(tokens)->destroy();
	return (arr);
}
