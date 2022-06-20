/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:47:34 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/20 15:30:13 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>
#include <string_util.h>

int	ft_separator(const char *str)
{
	int	i;

	i = 0;
	while (str && *str)
	{
		if (string().contains(SEPARADOES, _str(*str++)))
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_rmv_quotes(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*mem;

	if (!str || !*str)
		return (NULL);
	i = -1;
	size = 0;
	while (str[++i])
		if (!(!is_quotes(str, i) && (str[i] == '\"' || str[i] == '\'')))
			size++;
	mem = malloc_ob(sizeof(char) * (size + 1));
	mem[size] = 0;
	i = -1;
	j = 0;
	while (str[++i])
		if (!(!is_quotes(str, i) && (str[i] == '\"' || str[i] == '\'')))
			mem[j++] = str[i];
	return (mem);
}

int	ft_sep_move(const char *str)
{
	if (!str || !*str)
		return (0);
	else if (ft_separator(str) != 1)
		return (0);
	else if (*(str + 1) && str[0] == str[1] && ft_separator(str))
		return (2);
	else if (ft_separator(str))
		return (1);
	else
		return (0);
}

// ft_count_quotes,
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
static int	*ft_count_quotes(const char *str, int index, int *arr)
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

// is_quotes,
// return 0 -> not quoted ()
// return 1 -> double quoted ("")
// return 2 -> single quoted ('')
// return 3 -> both quoted ("" '') (this is not possible i think)
int	is_quotes(const char *str, int index)
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
