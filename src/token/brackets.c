/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:00:38 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/24 20:05:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

static int	ft_count_brackets(const char *str, int *arr, int index)
{
	int	i;

	i = 0;
	while (i < 4)
		arr[i++] = 0;
	i = -1;
	while (str[++i] && i < index)
	{
		arr[0] += (str[i] == '(' && !is_quotes(str, i));
		arr[1] += (str[i] == ')' && !is_quotes(str, i));
	}
	arr[2] += (str[index] == '(' && !is_quotes(str, i));
	arr[1] += (str[index] == ')' && !is_quotes(str, i));
	i = index;
	while (str[++i])
	{
		arr[2] += (str[i] == '(' && !is_quotes(str, i));
		arr[3] += (str[i] == ')' && !is_quotes(str, i));
	}
	return (arr[0] || arr[1] || arr[2] || arr[3]);
}

// returns -1 if there is a error in brackects numbers
// else returns level inside brackets (lvl 0 -> no brackects)
int	ft_handle_brackets(const char *str, int index)
{
	int	open;
	int	arr[4];

	ft_count_brackets(str, arr, index);
	open = arr[0] - arr[1];
	if ((arr[0] + arr[1] + arr[2] + arr[3]) % 2 != 0)
		return (-1);
	else
		return (open);
}
