/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/27 14:29:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTIL_H
# define STRING_UTIL_H

# include <stdlib.h>

char			*__join(const char *str1, const char *str2);
char			**__split(char const *s, char c, int j, char **list);
char			*__copy_n(const char *str, int n);
char			*__str_trim(const char *str);
int				__equals(const char *str1, const char *str2);
int				__equals_n(const char *str1, const char *str2, int n);
int				__is_space(char c);

#endif
