/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:39:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/31 22:43:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_command_util.h>

static t_command	*cread_cmd(char *s)
{
	if (string().equals_n(s, ">", 1))
		return (new_redirect_output(s));
	if (string().equals_n(s, "<", 1))
		return (new_redirect_input(s));
	if (string().equals_n(s, "cd", 2 && (!s[2] || string().is_space(s[2]))))
		return (new_cd(s));
	if (string().equals_n(s, "echo", 4) && (!s[4] || string().is_space(s[4])))
		return (new_echo(s));
	if (string().equals_n(s, "pwd", 3) && (!s[3] || string().is_space(s[3])))
		return (new_pwd(s));
	if (string().equals_n(s, "env", 3) && (!s[3] || string().is_space(s[3])))
		return (new_env(s));
	if (string().equals_n(s, "teste", 5) && (!s[5] || string().is_space(s[5])))
		return (new_teste(s));
	if (string().equals_n(s, "export", 6) && (!s[6] || string().is_space(s[6])))
		return (new_export(s));
	return (new_command(s));
}

static void	execute(t_terminal	*t, char	*line)
{
	char		**argv;
	t_command	*c;
	int			i;

	argv = token(line);
	if (!argv)
		return ;
	i = 0;
	c = 0;
	while (argv && argv[i] && t->commands)
	{
		//printf("%s\n", argv[i]);
		c = cread_cmd(argv[i]);
		if (c && c->init(c, argv[i], data()->envp))
			list(t->commands)->add(c);
		i++;
	}
	c = new_command(NULL);
	c->index = __COMMAND_BEGING_;
	pipe(c->fd);
	list(t->commands)->add(new_console(NULL));
	terminal()->check_command_args(list(t->commands)->get(0));
	(list(t->commands)->get(0))->input(c, list(t->commands)->get(0));
	list(t->commands)->beging = NULL;
	c->destroy(c);
}

static void	ft_input(void)
{
	t_terminal	*t;
	char		*line;
	int			i;
	char		**str;

	t = this()->terminal;
	if (!t)
		return ;
	i = -1;
	while (data()->envp && data()->envp[++i])
	{
		str = string().split(data()->envp[i], "=");
		if (string().size_list(str) > 1)
			(hashmap(t->envp))->put(str[0], str[1]);
	}
	while (1)
	{
		line = readline(t->title);
		add_history(line);
		execute(t, line);
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
	t->commands = new_list();
	t->wildcards = __wildcards;
	t->check_command_args = __check_args;
	t->get_exts = __get_exts;
	t->is_erro_cmd = 0;
	t->pid = getpid();
	t->envp = new_hashmap();
	this()->terminal = t;
	return (t);
}

t_terminal	*terminal(void)
{
	return (this()->terminal);
}
