/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/04 11:36:54 by edos-san         ###   ########.fr       */
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
	void				*cmds;
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

//						commadas
t_command				*new_command(void);
t_command				*new_console(void);
t_command				*new_redirect_output(void);
t_command				*new_redirect_input(void);
t_command				*new_cd(void);
t_command				*new_echo(void);
t_command				*new_pwd(void);
t_command				*new_env(void);
t_command				*new_teste(void);
t_command				*new_export(void);
t_command				*new_minishell(void);
t_command				*new_unset(void);

#endif
