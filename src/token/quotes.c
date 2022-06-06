/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/04 12:09:35 by edos-san         ###   ########.fr       */
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

/*
is_quotes,
return 0 -> not quoted ()
return 1 -> double quoted ("")
return 2 -> single quoted ('')
return 3 -> both quoted ("" '') (this is not possible i think)
*/
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

void	*ft_divide_quotes(const char *str)
{
	void	*cmds;
	int		i;

	cmds = new_array();
	i = -1;
	while (str[++i])
	{
		if ((string().is_space(str[i]) || (i == (ft_separator(str) - 1))) \
		&& !is_quotes(str, i))
		{
			(array(cmds))->add(string().copy_n(str, i));
			str += i + !(i == (ft_separator(str) - 1));
			i = 0;
			if (!(ft_separator(str) - 1))
			{
				while (ft_separator(str + i) - 1 == i)
					i++;
				(array(cmds))->add(string().copy_n(str, i));
				str += i;
				i = 0;
			}
		}
	}
	(array(cmds))->add(string().copy_n(str, i));
	return (cmds);
}

void	*ft_divide_cmds(void *list)
{
	void	*cmds;
	void	*token;
	char	*str;
	int		i;

	i = -1;
	cmds = new_array();
	token = new_array();
	while (++i < array(list)->size)
	{
		str = array(list)->get(i);
		if (ft_separator(str))
		{
			array(token)->add(cmds);
			cmds = new_array();
			if (!string().equals(str, "|"))
				array(cmds)->add(string().trim(str));
		}
		else
			array(cmds)->add(string().trim(str));
	}
	array(token)->add(cmds);
	array(list)->destroy();
	return (token);
}
