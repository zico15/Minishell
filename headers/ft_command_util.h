/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_util.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/06 21:34:34 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMAND_UTIL_H
# define FT_COMMAND_UTIL_H

# include <ft_command.h>

char	*__wildcards(const char *exts);
void	__check_args(t_command *t);
char	*__get_exts(const char *str);
void	__sigaction(char *str);
void	__update_env(void);
void	waitpid_all(t_element *e, void *o);
void	__destroy_terminal(char *msg);

#endif
