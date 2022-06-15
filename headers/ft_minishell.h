/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 13:03:13 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <ft_command.h>
# include <ft_string.h>
# include <ft_terminal.h>
# include <ft_util.h>
# include <ft_read_line.h>
# include <ft_token.h>
# include <readline/readline.h>
# include <readline/history.h>

# define FD_WRITE_O 1
# define FD_READ_O 0
# define CREATED_1 "(amaria-m) António Maria Mouro Ferreira Abranches Pinto"
# define CREATED_2 "(edos-san) Ezequiel Carlos Dos Santos"
# define __ERROR_MEMORY_ "Error: memory not allocated.\n"
# define __ERROR_PIPE_ "Error: opening pipe.\n"

typedef int	t_pid;

enum e_boolean
{
	false,
	true
};

typedef struct s_memory
{
	int			malloc_size;
	int			free_size;
}	t_memory;

void		rl_replace_line(const char *text, int clear_undo);
void		rl_clear_history(void);

//			UTIL
char		*get_path(t_command	*c, char *arg, const char *path);
t_terminal	*terminal(void);
t_memory	*memory(void);

//			TESTE
void		printf_cmd(t_command **c);
void		init_keys(void);

#endif
