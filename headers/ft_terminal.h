/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 18:41:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H

# include <stdlib.h>
# include <stdio.h>
# include <ft_command.h>

# define __MINISHELL_PID__ "__MINISHELL__PID__"

typedef struct s_terminal	t_terminal;

struct s_terminal
{
	char				*title;
	int					fd[2];
	pid_t				pid;
	pid_t				pid_parent;
	int					is_erro_cmd;
	void				*commands;
	void				*envp;
	void				(*input)(void);
	char				*(*wildcards)(const char *exts);
	char				*(*get_exts)(const char *str);
	void				(*check_command_args)(t_command *this);
	void				(*sigaction)(char *str);
	void				(*update_env)(void);
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
t_command				*new_export(char *arg);
t_command				*new_minishell(char *arg);
t_command				*new_unset(char *arg);

#endif
