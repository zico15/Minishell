/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 16:45:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_LINE_H
# define FT_READ_LINE_H

# include <ft_terminal.h>
# include <stdlib.h>
# include <ft_base_array.h>

typedef struct s_read	t_read;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999999
# endif

char	*get_next_line(int fd);

#endif
