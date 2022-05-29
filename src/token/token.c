/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/29 10:41:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

char	**token(char *line)
{
	int		i;
	int		j;
	int		separator;
	void	*tokens;

	if (!line)
		return (ft_exit());
	if (!(*line))
		return (NULL);
	tokens = new_array();
	i = 0;
	separator = 0;
	line = ft_dollar(line);
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
	return (ft_lst_to_arr(tokens));
}
