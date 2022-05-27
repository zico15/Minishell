/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:39:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/27 17:22:33 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

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
	(list(t->commands)->get(0))->input(c, list(t->commands)->get(0));
	list(t->commands)->beging = NULL;
	c->destroy(c);
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
	this()->terminal = t;
	return (t);
}
