/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:39:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/23 20:01:32 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
#include <ft_command_util.h>
#include <termios.h>

static void	cread_cmd(t_element *e, void *cmds)
{
	t_command	*cmd;
	t_command	*previou;
	t_element	*c;
	char		**list;
	void		*token;

	token = e->value;
	if (!token)
		return ;
	list = array(token)->to_str();
	if (!list)
		return ;
	cmd = __get_cmd(*list);
	if (cmd && cmd->init(cmd, list))
	{
		cmd->index = array(cmds)->size;
		previou = array(cmds)->get(array(cmds)->size - 1);
		if (previou)
			previou->next = cmd;
		c = array(cmds)->add(cmd);
		if (c)
			c->destroy = command_destroy_element;
	}
	else
		free_list(list);
}

static void	execute(t_terminal	*t, void *token)
{
	static t_command	start;

	start.index = __COMMAND_BEGING_;
	start.fd[0] = dup(0);
	start.fd[1] = dup(1);
	if (!token)
		return ;
	t->cmds = new_array();
	(array(token))->for_each(cread_cmd, t->cmds);
	array(token)->destroy();
	start.next = array(t->cmds)->get(0);
	close(start.fd[1]);
	(terminal())->next_command(NULL, &start);
	(array(t->cmds))->for_each(waitpid_all, 0);
	array(t->cmds)->destroy();
	t->cmds = NULL;
}

static void	ft_init(void)
{
	char			*str;
	char			*line;

	while (1)
	{
		str = NULL;
		line = test_file();
		if (terminal()->fd_test == -1)
			line = readline(terminal()->get_title());
		if (line && *line)
		{
			str = string().copy(line);
			add_history(str);
			array(terminal()->history)->add(str);
			free_ob(line);
			line = str;
		}
		execute(terminal(), token(line));
	}
}

t_terminal	*new_terminal(char *title, char *color, char **env)
{
	static t_terminal	t;

	t.init = ft_init;
	t.get_title = __get_title;
	t.title = string().copy(title);
	t.color = string().copy(color);
	t.wildcards = __wildcards;
	t.check_command_args = __check_args;
	t.get_exts = __get_exts;
	t.pid = getpid();
	t.pid_parent = -1;
	t.get_cmd = __get_cmd;
	t.sigaction = __sigaction;
	t.envp = new_hashmap();
	t.update_env = __update_env;
	t.destroy = __destroy_terminal;
	t.envp_to_str = env;
	t.print_error = __print_error;
	t.history = new_array();
	t.next_command = __next_command;
	t.fd_test = -1;
	this()->terminal = &t;
	init_env(this()->terminal);
	return (this()->terminal);
}
