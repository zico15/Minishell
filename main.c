/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/06 21:33:34 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_pipex.h"

// -fsanitize=address -g
//echo """dsfdsfss""" "s" """'oi'"""
int	main(int argc, char **argv, char **envp)
{
	t_terminal	*t;

	(void) argc;
	(void) argv;
	init_keys();
	t = new_terminal("\033[0;32mbash-3.3$\033[0m ", envp);
	t->input();
	return (0);
}
