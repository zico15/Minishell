/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:39:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/14 18:05:57 by edos-san         ###   ########.fr       */
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

/*
static void	print_cmd(t_element *e, void *o)
{
	int i = 0;
	(void) o;
	t_command *c;
	c = e->value;
	printf("================\n");
	printf("CMD:");
	while (c && c->commands && c->commands[i])
		printf(" %s", c->commands[i++]);
	printf("\n");
}*/
void	execute(t_terminal	*t, void *token)
{
	t_command	*c;
	t_command	*run;

	if (!token)
		return ;
	t->cmds = new_array();
	c = new_command();
	c->pid = 0;
	c->index = __COMMAND_BEGING_;
	pipe(c->fd);
	(array(token))->for_each(cread_cmd, t->cmds);
	array(token)->destroy();
	run = array(t->cmds)->get(0);
	terminal()->check_command_args(run);
	//close(c->fd[0]);
	run->input(c, run);
	c->destroy(c);
	(array(t->cmds))->for_each(waitpid_all, 0);
	array(t->cmds)->destroy();
	t->cmds = NULL;
}

static void	ft_init(void)
{
	t_terminal		*t;
	char			*str;
	char			*line;
	struct termios	ter;

	tcgetattr(0, &ter);
	ter.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &ter);
	t = this()->terminal;
	if (!t)
		return ;
	while (1)
	{
		str = NULL;
		line = readline(t->get_title());
		if (line && *line)
		{
			str = string().trim(line);
			add_history(str);
			array(terminal()->history)->add(str);
			str = check_dolar(t->envp, line, 0, string().size(line));
			line = str;
		}
		execute(t, token(line));
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
	t.is_erro_cmd = 0;
	t.pid = getpid();
	t.cmds = NULL;
	t.pid_parent = -1;
	t.get_cmd = __get_cmd;
	t.sigaction = __sigaction;
	t.envp = new_hashmap();
	t.update_env = __update_env;
	t.destroy = __destroy_terminal;
	t.envp_to_str = env;
	t.status_exit = 0;
	t.print_error = __print_error;
	t.history = new_array();
	this()->terminal = &t;
	init_env(this()->terminal);
	return (this()->terminal);
}
