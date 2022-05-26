/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/26 18:08:32 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_pipex.h>


// -fsanitize=address -g
int	main2(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	void *tokens;

	tokens = new_array();
	(void) tokens;

	return (0);
}
