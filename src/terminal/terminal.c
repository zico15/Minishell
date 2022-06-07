/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:39:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/07 20:40:51 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_command_util.h>

static t_command	*get_cmd(char *s)
{
	if (string().equals(s, ">"))
		return (new_redirect_output());
	if (string().equals(s, "<"))
		return (new_redirect_input());
	if (string().equals(s, "cd"))
		return (new_cd());
	if (string().equals(s, "echo"))
		return (new_echo());
	if (string().equals(s, "pwd"))
		return (new_pwd());
	if (string().equals(s, "env"))
		return (new_env());
	if (string().equals(s, "teste"))
		return (new_teste());
	if (string().equals(s, "export"))
		return (new_export());
	if (string().equals(s, "minishell"))
		return (new_minishell());
	if (string().equals(s, "unset"))
		return (new_unset());
	return (new_command());
}

static void	cread_cmd(t_element *e, void *cmds)
{
	t_command	*cmd;
	t_command	*previou;
	char		**list;
	void		*token;

	token = e->value;
	if (!token)
		return ;
	e->destroy = NULL;
	list = array(token)->to_str();
	if (!list)
		return ;
	cmd = get_cmd(*list);
	if (cmd && cmd->init(cmd, list))
	{
		cmd->index = array(cmds)->size;
		previou = array(cmds)->get(array(cmds)->size - 1);
		if (previou)
			previou->next = cmd;
		array(cmds)->add(cmd);
	}
	array(token)->destroy();
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
static void	execute(t_terminal	*t, char	*line)
{
	void		*tokens;
	t_command	*c;
	t_command	*run;

	tokens = token(line);
	if (!tokens)
		return ;
	c = new_command();
	c->index = __COMMAND_BEGING_;
	pipe(c->fd);
	(array(tokens))->for_each(cread_cmd, t->cmds);
	array(tokens)->destroy();
	run = array(t->cmds)->get(0);
	terminal()->check_command_args(run);
	run->input(c, run);
	c->destroy(c);
	(array(t->cmds))->for_each(waitpid_all, 0);
	array(t->cmds)->destroy();
	t->cmds = new_array();
}

static void	ft_input(void)
{
	t_terminal	*t;
	char		*line;

	t = this()->terminal;
	if (!t)
		return ;
	while (1)
	{
		line = readline(t->title);
		add_history(line);
		execute(t, check_dolar(t->envp, line, 0, string().size(line)));
	}
}

t_terminal	*new_terminal(char *title)
{
	t_terminal	*t;

	t = malloc(sizeof(t_terminal));
	if (!t)
		return (0);
	t->input = ft_input;
	t->title = title;
	t->cmds = new_array();
	t->wildcards = __wildcards;
	t->check_command_args = __check_args;
	t->get_exts = __get_exts;
	t->is_erro_cmd = 0;
	t->pid = getpid();
	t->pid_parent = -1;
	t->sigaction = __sigaction;
	t->envp = new_hashmap();
	t->update_env = __update_env;
	t->destroy = __destroy_terminal;
	this()->terminal = t;
	init_env(t);
	return (t);
}
