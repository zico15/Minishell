/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/30 17:15:24 by amaria-m         ###   ########.fr       */
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
// 									^

int	*ft_count_quotes(char *str, int index, int *arr)
{
	int	i;

	i = 0;
	while (i < 4)
		arr[i++] = 0;
	i = index;
	while (str[--i] && i >= 0)
	{
		arr[0] += (str[i] == '\"');
		arr[1] += (str[i] == '\'');
	}
	i = index;
	while (str[++i])
	{
		arr[2] += (str[i] == '\'');
		arr[3] += (str[i] == '\"');
	}
	return (arr);
}

/*
ft_handle_quotes, 
removes all quotes from each argument of the list 
if the argument doesnt have a dollar sign in it
*/

void	ft_handle_quotes(void *tokens)
{
	int		i;

	i = -1;
	while (++i < array(tokens)->size)
	{
		if (!string().contains(array(tokens)->get(i), "$"))
		{
			while (string().contains(array(tokens)->get(i), "\""))
				(array(tokens))->set(i, \
				string().replace(array(tokens)->get(i), "", "\""));
			while (string().contains(array(tokens)->get(i), "\'"))
				(array(tokens))->set(i, \
				string().replace(array(tokens)->get(i), "", "\'"));
		}
	}
}

// echo "bla bla '$TERM' bla bla ''$TERM''"
