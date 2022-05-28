/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/28 17:33:34 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H

# include <stdlib.h>
# include <stdio.h>
# include <ft_command.h>

typedef struct s_terminal	t_terminal;

struct s_terminal
{
	char				*title;
	int					fd[2];
	void				*commands;
	void				(*input)(void);
	char				*(*wildcards)(char *exts);
	void				(*check_command_args)(t_command *this);
	t_terminal			*next;
};

t_terminal				*new_terminal(char *title);
char					**token(char *line);

//						commadas
t_command				*new_command(char *arg);
t_command				*new_console(char *arg);
t_command				*new_redirect_output(char *arg);
t_command				*new_redirect_input(char *arg);
t_command				*new_cd(char *arg);
t_command				*new_echo(char *arg);
t_command				*new_pwd(char *arg);
t_command				*new_env(char *arg);
t_command				*new_teste(char *arg);

#endif
