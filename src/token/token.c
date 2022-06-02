/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/02 19:18:48 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

static int	ft_move_j(char *line, int i, int j, int *separator)
{
	j = i;
	while (line[j] && (ft_inside_quotes(line, j) || *separator \
	|| ft_separator(line[j])))
	{
		if (ft_separator(line[j++]))
			*separator = 0;
	}
	return (j);
}

char	**token(char *line)
{
	int		i;
	int		j;
	int		separator;
	void	*tokens;

	if (!line)
		return (ft_send_exit());
	if (!(*line))
		return (NULL);
	tokens = new_array();
	i = 0;
	separator = 0;
	while (line[i])
	{
		j = ft_move_j(line, i, j, &separator);
		if (j > i)
		{
			separator = 1;
			(array(tokens))->add(string().copy_n(line + i + \
			(line[i] == '|'), j - i - (line[i] == '|')));
		}
		i = j;
	}
	return (ft_lst_to_arr(tokens));
}
