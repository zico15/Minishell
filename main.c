/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/11 16:21:39 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_pipex.h"

// -fsanitize=address -g
//echo """dsfdsfss""" "s" """'oi'"""
int	main(int argc, char **argv, char **env)
{
	t_terminal	*t;

	(void) argc;
	(void) argv;
	init_keys();
	t = new_terminal("\033[0;32mbash-3.3$\033[0m ", env);
	t->init();
	return (0);
}
