/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/08 22:51:04 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	if (!(this->execute(this, previou->fd[0], this->fd[1])))
	{
		if (this->commands)
			print_msg_error(this, __COMMAND_NOT_FOUND__, 1);
		close(this->fd[1]);
	}
	next_command(previou, this);
	return (this->fd);
}

static int	execute(t_command *this, int input, int out)
{
	int		status;

	this->pid = fork();
	status = 0;
	if (!this->pid)
	{
		if (!this->is_print && this->next && (dup2(out, 1) < 0 || close(out)))
			exit(0);
		if (dup2(input, 0) < 0 || close(input))
			exit(0);
		status = execve(this->path, this->commands, terminal()->envp_to_str);
		exit(errno);
	}
	close(input);
	close(out);
	return (1);
}

static int	init(t_command *this, char **args)
{
	t_element	*e;
	char		*path;
	int			i;

	i = -1;
	this->path[0] = 0;
	e = hashmap(terminal()->envp)->get_key("PATH");
	if (e)
	{
		path = e->value;
		get_path(this, *args, path);
	}
	this->commands = args;
	if (pipe(this->fd) == __PIPE_ERROR__)
		return (0);
	return (1);
}

static int	*ft_destroy(t_command *this)
{
	static int	fd[2] = {-1, -1};

	if (this)
	{
		close(this->fd[0]);
		close(this->fd[1]);
		free_list(this->commands);
	}
	return (fd);
}

t_command	*new_command(void)
{
	t_command	*c;

	c = malloc_ob(sizeof(t_command));
	if (!c)
	{
		printf("err: %s\n", "malloc_ob");
		return (0);
	}
	c->input = ft_input;
	c->init = init;
	c->execute = execute;
	c->destroy = ft_destroy;
	c->fd[0] = -1;
	c->fd[1] = -1;
	c->pid = 0;
	c->index = -1;
	c->next = NULL;
	c->path[0] = 0;
	c->is_print = 0;
	c->commands = NULL;
	return (c);
}
