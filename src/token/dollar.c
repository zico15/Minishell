/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/27 20:36:58 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

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

int ft_read_dollar(char *str, int index)
{
	int	i;
	int	*arr;

	arr = malloc(sizeof(int) * 4);
	arr = ft_count_quotes(str, index, arr);
	i = -1;
	while (++i < 4)
		printf("arr %i: %i\n", i, arr[i]);
	free(arr);
	return (0);
}

char    *ft_dollar(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$')
		{
			if (!ft_read_dollar(str, i))
				break;
		}
		i++;
	}
	return (str);
}

// echo "$TERM"
// echo 