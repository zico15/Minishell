/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:39:34 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 19:28:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/ft_pipex.h"

static t_command	*cread_cmd(char *arg)
{
	if (string().contains(arg, ">") == true)
		return (new_redirect_output(arg));
	if (string().contains(arg, "<") == true)
		return (new_redirect_input(arg));
	return (new_command(arg));
}

static void	execute(t_terminal	*t, char	*line)
{
	char		**argv;
	t_command	*c;
	int			i;

	argv = token(line);
	i = 0;
	(void) t;
	c = 0;
	while (argv && argv[i] && t->commands)
	{
		c = cread_cmd(argv[i]);
		if (c && c->init(c, argv[i], data()->envp))
			list(t->commands)->add(c);
		i++;
	}
	c = new_command(NULL);
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
		line = read_line(t);
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
