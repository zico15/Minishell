/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/31 18:30:42 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

// ft_count_quotes
// receives the string that contains the commands (str),
// receives the index of the character that is possibly 
// surrounded by quotes (index)
// and the adress of an ARRAY OF 4 INTEGERS (arr).
// arr will be returned containing the amount of times each quotation appears:
// arr[0] :  "number of times DOUBLE QUOTE appears at the LEFT of index"
// arr[1] :  "number of times SINGEL QUOTE appears at the LEFT of index"
// arr[2] :  "number of times SINGEL QUOTE appears at the RIGHT of index"
// arr[3] :  "number of times DOUBLE QUOTE appears at the RIGHT of index"
// example: str = (hello "world" this '$TERM' is in '42') | index = 21
// |-> arr = {2, 1, 3, 0}

int	*ft_count_quotes(char *str, int index, int *arr)
{
	int	i;

	i = 0;
	while (i < 4)
		arr[i++] = 0;
	i = -1;
	while (str[++i] && i < index)
	{
		arr[0] += (str[i] == '\"' && arr[1] % 2 == 0);
		arr[1] += (str[i] == '\'' && arr[0] % 2 == 0);
	}
	arr[0] += (str[index] == '\"' && arr[1] % 2 == 0 && arr[0] % 2 != 0);
	arr[1] += (str[index] == '\'' && arr[0] % 2 == 0 && arr[1] % 2 != 0);
	i = index;
	while (str[++i])
	{
		arr[2] += (str[i] == '\'' && (arr[0] + arr[3]) % 2 == 0);
		arr[3] += (str[i] == '\"' && (arr[1] + arr[2]) % 2 == 0);
	}
	return (arr);
}

/*
ft_inside_quotes,
return 0 -> not quoted ()
return 1 -> double quoted ("")
return 2 -> single quoted ('')
return 3 -> both quoted ("" '') (this is not possible i think)
*/

int	ft_inside_quotes(char *str, int index)
{
	int	d_quoted;
	int	s_quoted;
	int	arr[4];

	ft_count_quotes(str, index, arr);
	d_quoted = (arr[0] % 2 != 0 && arr[3] % 2 != 0);
	s_quoted = (arr[1] % 2 != 0 && arr[2] % 2 != 0);
	if (d_quoted && !s_quoted)
		return (DOUBLE_QUOTED);
	else if (!d_quoted && s_quoted)
		return (SINGLE_QUOTED);
	else if (d_quoted && s_quoted)
		return (BOTH_QUOTED);
	return (NOT_QUOTED);
}

int	ft_count_cmd(char *str)
{
	int	i;
	int	str_count;

	if (!str || !*str)
		return (0);
	str_count = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_inside_quotes(str, i) > 0)
			str_count++;
		while (str[i] && ft_inside_quotes(str, i) > 0)
			i++;
		if (str[i] && str[i] != '\"' && str[i] != '\'' && !string().is_space(str[i]) && ft_inside_quotes(str, i) == 0)
			str_count++;
		while (str[i] && str[i] != '\"' && str[i] != '\'' && !string().is_space(str[i]) && ft_inside_quotes(str, i) == 0)
			i++;
	}
	return (str_count);
}

// char	**ft_divide_cmd(char *str, int n)
// {
// 	char	**cmds;
// 	int		i;
// 	//int		j;

// 	if (!n || !str || !*str)
// 		return (NULL);
// 	cmds = malloc(sizeof(char*) * (n + 1));
// 	cmds[n] = NULL;
// 	i = -1;
// 	// while (++i < n)
// 	// {
// 	// 	j = -1;
// 	// 	// while (str[++j])
// 	// 	// {
// 	// 	// 	if (ft_inside_quotes(str, j) > 0)
// 	// 	// 		str_count++;
// 	// 	// 	while (str[j] && ft_inside_quotes(str, j) > 0)
// 	// 	// 		i++;
// 	// 	// 	if (str[j] && str[j] != '\"' && str[j] != '\'' && !string().is_space(str[j]) && ft_inside_quotes(str, j) == 0)
// 	// 	// 		str_count++;
// 	// 	// 	while (str[j] && str[j] != '\"' && str[j] != '\'' && !string().is_space(str[j]) && ft_inside_quotes(str, j) == 0)
// 	// 	// 		j++;
// 	// 	// }
// 	// }
// }