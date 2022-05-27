/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/27 16:35:55 by amaria-m         ###   ########.fr       */
=======
/*   Updated: 2022/05/27 14:29:40 by edos-san         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

typedef struct s_string
{
	int			(*contains)(const char *str, const char *hey);
	char		**(*split)(const char *s, char c);
	int			(*size)(const char *s);
	char		*(*copy)(const char *str);
	char		*(*join)(const char *str1, const char *str2);
	char		*(*copy_n)(const char *str, int n);
	char		*(*trim)(const char *str);
<<<<<<< HEAD
	char		*(*strnstr)(const char *haystack, const char *needle, size_t len);
=======
	int			(*equals)(const char *str1, const char *str2);
	int			(*equals_n)(const char *str, const char *hey, int n);
	int			(*is_space)(char c);
>>>>>>> main
}	t_string;

t_string	string(void);

#endif
