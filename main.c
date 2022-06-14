/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/13 18:27:47 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_minishell.h"

// -fsanitize=address -g
//echo """dsfdsfss""" "s" """'oi'"""
int	main(int argc, char **argv, char **env)
{
	t_terminal	*t;

	(void) argc;
	(void) argv;
	init_keys();
	t = new_terminal("bash-3.3$", "\033[0;32m", env);
	t->init();
	return (0);
}
