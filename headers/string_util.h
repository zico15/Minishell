/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/27 16:35:04 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_UTIL_H
# define STRING_UTIL_H

# include <stdlib.h>

char			*__join(const char *str1, const char *str2);
char			**__split(char const *s, char c, int j, char **list);
char			*__copy_n(const char *str, int n);
char			*__str_trim(const char *str);
char			*__strnstr(const char *haystack, const char *needle, size_t len);

#endif
