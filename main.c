/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/18 17:33:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_minishell.h"

static void	init_home(t_terminal *t, int i, int j)
{
	char		*home;
	char		*user;
	char		*pwd;
	static char	buff[BUFFER_SIZE];
	char		*temp;

	temp = "/Users/";
	home = getenv("HOME");
	user = getenv("USER");
	pwd = getenv("PWD");
	while (temp[i])
	{
		buff[i] = temp[i];
		i++;
	}
	while (user && *user)
		buff[i++] = *user++;
	temp = home;
	if (string().equals(home, buff))
		temp = buff;
	else if (string().contains(pwd, buff))
		temp = buff;
	t->home[0] = 0;
	while (temp && temp[++j])
		t->home[j] = temp[j];
}

// -fsanitize=address -g
//echo """dsfdsfss""" "s" """'oi'"""
int	main(int argc, char **argv, char **env)
{
	t_terminal	*t;

	init_keys();
	t = new_terminal("bash-3.3$", "\033[0;32m", env);
	if (argc > 1)
		t->fd_test = open(argv[1], O_RDONLY);
	init_home(t, 0, -1);
	t->init();
	return (0);
}
