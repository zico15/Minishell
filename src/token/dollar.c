/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/27 14:39:46 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

char    *ft_dollar(char *str)
{
    if (string().contains(str, "$"))
        printf("dollar index: %i\n", string().contains(str, "$"));
    return (str);
}