/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/09 15:22:19 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

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
