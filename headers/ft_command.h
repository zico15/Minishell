/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/05 18:37:11 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMAND_H
# define FT_COMMAND_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

typedef struct s_command	t_command;
typedef struct s_list_cmd	t_list_cmd;

# define __COMMAND_NOT_FOUND__ "command not found"
# define __COMMAND_NOT_FILE__ "No such file or directory"
# define __COMMAND_BEGING_ -1
# define __COMMAND_END__ -2
# define __PIPE_ERROR__ -1

struct s_command
{
	pid_t				pid;
	int					index;
	char				path[1000];
	int					fd[2];
	id_t				is_print;
	char				**commands;
	int					*(*input)(t_command *previou, t_command *this);
	int					(*init)(t_command *this, char **args);
	int					(*execute)(t_command *this, int input, int out);
	int					*(*destroy)(t_command *this);
	struct s_command	*next;
};

struct s_list_cmd
{
	t_command			*beging;
	t_command			*end;
	t_command			*this;

	t_command			*(*add)(t_command *cmd);
	t_command			*(*get)(int index);
	void				(*forEach)(void (*fun)(t_command **cmd));
	t_command			*(*teste)(t_command *cmd);
};

void					*new_list(void);
t_list_cmd				*list(t_list_cmd *t);
void					list_clear(t_command **c);
int						next_command(t_command *previou, t_command *this);

#endif
