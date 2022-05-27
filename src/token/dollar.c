/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/27 17:05:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>

int ft_read_dollar(char *str, int index)
{
    char    *quote;
    int s_quote;
    int d_quote;

    s_quote = 0;
    d_quote = 0;
    quote = string().strnstr(str, "\'", string().size(str));
    if (quote)
        s_quote = (string().strnstr(str, "\'", string().size(str)) - str);
    quote = string().strnstr(str, "\"", string().size(str));
    if (quote)
        d_quote = (string().strnstr(str, "\"", string().size(str)) - str);
    return(str)
    
    
}

char    *ft_dollar(char *str)
{
    char    *cpy;
    char    *mem;

    mem = string().strnstr(str, "$", string().size(str));
    if (mem)
    {
        cpy = string().copy_n(str, mem - str);
        //printf("%s\n", cpy);
        free(cpy);
    }
    return (str);
}