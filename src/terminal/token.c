/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:58 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/26 16:44:13 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static char	**ft_exit()
{
	char	**arr;

	write(1, "\r", 1);
	arr = malloc(sizeof(char *) * 2);
	*arr = string().copy("exit");
	arr[1] = NULL;
	return (arr);
}

static int	ft_separator(char l)
{
	if (l == '|' || l == '>' || l == '<')
		return (0);
	return (1);
}

static int	ft_quotes(char	*letter)
{
	static int	d_quote;
	static int	s_quote;

	if (*letter == '\'' && !s_quote)
		s_quote = 1;
	else if (*letter == '\'' && s_quote)
		s_quote = 0;
	else if (*letter == '\"' && !d_quote)
		d_quote = 1;
	else if (*letter == '\"' && d_quote)
		d_quote = 0;
	return (d_quote || s_quote);
}

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
		{
			if (ft_separator(line[j]))
				separator = 0;
			j++;
		}
		if (j > i)
		{
			separator = 1;
			array(tokens)->add(string().copy_n(line + i + (line[i] == '|'), j - i - (line[i] == '|')));
		}
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
