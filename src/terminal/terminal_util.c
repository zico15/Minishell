/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:55:13 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/08 22:54:11 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>
#include <ft_string.h>

void	__sigaction(char *str)
{
	t_terminal	*t;

	t = terminal();
	if (!t || !str || !*str)
		return ;
	if (string().contains(str, "export"))
		export_add(t, str);
	if (string().contains(str, "unset"))
		unset_remove(t, str);
}

void	__update_env(void)
{
	free_list(terminal()->envp_to_str);
	terminal()->envp_to_str = hashmap(terminal()->envp)->to_str();
}

void	waitpid_all(t_element *e, void *o)
{
	t_command	*c;
	int			status;

	(void) o;
	c = e->value;
	if (c)
		waitpid(c->pid, &status, 0);
}

void	__destroy_terminal(char *msg)
{
	if (terminal()->cmds)
		array(terminal()->cmds)->destroy();
	if (terminal()->envp)
		hashmap(terminal()->envp)->destroy();
	free_list(terminal()->envp_to_str);
	printf("memory-> malloc: %i free: %i\n", memory()->malloc_size, memory()->free_size);
	printf("%s", msg);
	exit(0);
}
