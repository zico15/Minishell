/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:47:34 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/02 19:21:30 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

char	**ft_send_exit(void)
{
	char	**arr;

	write(1, "\r", 1);
	arr = malloc(sizeof(char *) * 2);
	*arr = string().copy("exit");
	arr[1] = NULL;
	printf("exit\n");
	exit(0);
	return (arr);
}

int	ft_separator(char l)
{
	if (l == '|' || l == '>' || l == '<')
		return (0);
	return (1);
}

int	ft_quotes(char	*letter)
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

char	**ft_lst_to_arr(void	*tokens)
{
	char	**arr;
	int		i;

	i = -1;
	while (++i < array(tokens)->size)
		array(tokens)->set(i, string().trim(array(tokens)->get(i)));
	arr = array(tokens)->to_str();
	array(tokens)->destroy();
	return (arr);
}
