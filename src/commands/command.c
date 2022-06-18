/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:07 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/17 20:14:26 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/**
 * @brief Main function(virtual) to execute a command
 * @param previou  command previou
 * @param this command this
 * @return this->fd
 */
static int	*ft_input(t_command *previou, t_command *this)
{
	if (string().equals(this->path, *this->commands))
		this->is_print = 1;
	if (!(this->execute(this, previou->fd[0], this->fd[1])))
	{
		(terminal())->print_error(this, 127);
		close(this->fd[1]);
	}
	return (terminal()->next_command(previou, this));
}

/**
 * @brief Executes the actual command getting the input (0) 
 * of the previous command plus the output (1) of the 
 * current command
 * @param this  command this
 * @param input (0)
 * @param out	(1)
 * @return **** void
 */
static int	execute(t_command *this, int input, int out)
{
	this->pid = fork();
	if (!this->pid)
	{
		if (!this->is_print && this->next && (dup2(out, 1) < 0 || close(out)))
			exit(0);
		if (!this->is_print && (dup2(input, 0) < 0 || close(input)))
			exit(0);
		execve(this->path, this->commands, terminal()->envp_to_str);
		exit(127);
	}
	close(input);
	close(out);
	return (1);
}

static int	init(t_command *this, char **args)
{
	t_element	*e;
	int			i;

	i = -1;
	this->path[0] = 0;
	e = hashmap(terminal()->envp)->get_key("PATH");
	if (e)
		get_path(this, *args, e->value);
	this->commands = args;
	if (pipe(this->fd) == __PIPE_ERROR__)
		terminal()->destroy(__ERROR_PIPE_);
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
		free_ob(this);
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
	c->is_user = 1;
	c->status = 0;
	c->index = -1;
	c->next = NULL;
	c->path[0] = 0;
	c->is_print = 0;
	c->commands = NULL;
	return (c);
}
