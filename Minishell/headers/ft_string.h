/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:16 by edos-san         ###   ########.fr       */
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

}	t_string;

t_string	string(void);

#endif
