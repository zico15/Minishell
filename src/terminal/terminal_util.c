/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:55:13 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/18 11:21:44 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
#include <ft_string.h>
#include <string.h>
#include <errno.h>

void	__sigaction(char *str)
{
	t_terminal	*t;

	t = terminal();
	if (!t || !str || !*str)
		return ;
	if (string().contains(str, "export"))
		export_add(t, str);
	if (string().contains(str, "unset"))
		unset_remove(t, str);
}

void	__update_env(void)
{
	free_list(terminal()->envp_to_str);
	terminal()->envp_to_str = hashmap(terminal()->envp)->to_str();
}

void	waitpid_all(t_element *e, void *o)
{
	t_command	*c;

	(void) o;
	c = e->value;
	if (c && !*c->commands)
		return ;
	if (c && c->pid)
	{
		waitpid(c->pid, &c->status, 0);
		c->status = WEXITSTATUS(c->status);
	}
	if (c->status && (!c->pid || c->status == 127))
		(terminal())->print_error(c, c->status);
	terminal()->status_exit = c->status;
}

void	__print_error(t_command *this, int status)
{
	if (status == 1)
		printf("bash: %s: %s: No such file or directory\n", this->commands[0], this->commands[1]);
	else if (status == 127)
		printf("bash: %s: command not found\n", this->commands[0]);
	else if (status == 258)
		printf("bash: syntax error near unexpected token\n");
	this->status = status;
}

void	__destroy_terminal(char *msg)
{
	if (terminal()->cmds)
		array(terminal()->cmds)->destroy();
	if (terminal()->envp)
		hashmap(terminal()->envp)->destroy();
	free_ob(terminal()->title);
	free_ob(terminal()->color);
	free_list(terminal()->envp_to_str);
	rl_clear_history();
	array(terminal()->history)->destroy();
	printf("%s", msg);
	print_memory();
	exit(0);
}
