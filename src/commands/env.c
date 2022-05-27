/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:52:33 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/27 15:18:07 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>


static int	write_env(char	*env, int fd)
{
	char	*str;

	str = getenv(env);
	write(fd, env, string().size(env));
	write(fd, "=", 1);
	write(fd, str, string().size(str));
	return (write(fd, "\n", 1));
}

static void	write_list_env(int fd)
{
	int			i;
	static char	*list[26] = {
		"TERM_PROGRAM", "TERM", "HOMEBREW_TEMP", "SHELL", "TMPDIR",
		"TERM_PROGRAM_VERSION", "ORIGINAL_XDG_CURRENT_DESKTOP",
		"USER", "SSH_AUTH_SOCK", "__CF_USER_TEXT_ENCODING",
		"HOMEBREW_CACHE", "PATH", "_", "PWD", "LANG",
		"XPC_FLAGS", "XPC_SERVICE_NAME", "SHLVL",
		"HOME", "VSCODE_GIT_ASKPASS_MAIN", "LOGNAME",
		"VSCODE_GIT_IPC_HANDLE", "VSCODE_GIT_ASKPASS_NODE",
		"GIT_ASKPASS", "COLORTERM", NULL
	};

	i = 0;
	while (fd != -1 && list[i])
	{
		write_env(list[i++], fd);
	}
	close(fd);
}

static int	*ft_input(t_command *previou, t_command *this)
{
	if (pipe(this->fd) == __PIPE_ERROR__)
		return (0);
	write_list_env(this->fd[1]);
	next_command(previou, this);
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}



t_command	*new_env(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
