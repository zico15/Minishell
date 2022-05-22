/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 20:53:10 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

static int	*ft_input(t_command *previou, t_command *this)
{
	pipe(this->fd);
	if (this->path[0] && this->execute(this, previou->fd[0], this->fd[1]))
	{
		close(previou->fd[0]);
		close(previou->fd[1]);
		next_command(previou, this);
	}
	else if (this->commands)
		printf("%s %s\n", __COMMAND_NOT_FOUND__, this->commands[0]);
	return (this->fd);
}

static int	execute(t_command *this, int input, int out)
{
	pid_t	pit;

	pit = fork();
	if (!pit)
	{
		if (dup2(input, 0) < 0 || dup2(out, 1) < 0 || \
		close(input) || close(out))
			exit(0);
		execve(this->path, this->commands, data()->envp);
		exit(0);
	}
	waitpid(pit, NULL, 0);
	close(input);
	close(out);
	return (1);
}

static int	init(t_command *this, char *arg, char **envp)
{
	char		*path;
	int			i;

	i = -1;
	path = NULL;
	while (envp[++i] && !string().contains(path, "PATH="))
		path = envp[i];
	this->commands = string().split(arg, ' ');
	get_path(this, arg, path);
	return (1);
}

static int	*ft_destroy(t_command *this)
{
	static int	fd[2] = {-1, -1};

	if (this)
	{
		close(this->fd[0]);
		close(this->fd[1]);
		free_ob(this->arg);
		free_list(this->commands);
	}
	return (fd);
}

t_command	*new_command(char *arg)
{
	t_command	*c;

	c = malloc(sizeof(t_command));
	if (!c)
	{
		printf("err: %s\n", "malloc");
		return (0);
	}
	c->input = ft_input;
	c->init = init;
	c->execute = execute;
	c->destroy = ft_destroy;
	c->arg = arg;
	c->fd[0] = -1;
	c->fd[1] = -1;
	c->index = -1;
	c->next = NULL;
	c->path[0] = 0;
	c->commands = NULL;
	c->pid = data()->pid_base++;
	return (c);
}
