/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 10:25:31 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTIL_H
# define FT_UTIL_H

# include <ft_terminal.h>
# include <ft_base_array.h>
# include <ft_command.h>
# include <ft_read_line.h>

typedef struct s_this
{
	t_list_cmd		*list;
	t_terminal		*terminal;
	t_array			*array;
	t_read			*read;
	t_array			*array_main;
	t_hashmap		*hashmap;

}	t_this;

t_this		*this(void);

//			util
char		*read_all(int fd);
void		init_env(t_terminal *t);
void		ft_read_signal(int signal);
void		ft_send_msg(int pid_t, const char *msg);
void		export_add(t_terminal	*t, char *str);
void		unset_remove(t_terminal	*t, char *str);
void		check_dolar(t_element *e, void *o);
void		check_operator_or(t_command *this);
void		check_operator_and(t_command *this);
char		*check_bracket(const char *str);
char		*create_priority(int i);
void		check_nivel_priority(t_command *this);

//			memory
int			free_ob(void *v);
int			free_list(char **str);
void		*malloc_ob(size_t __size);

//			remove - testes
void		print_memory(void);

#endif
