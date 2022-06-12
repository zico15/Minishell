/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:55:13 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/12 12:34:26 by edos-san         ###   ########.fr       */
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
	status = 0;
	if (c)
		waitpid(c->pid, &status, 0);
	terminal()->status_exit = status;
}

/*printf("\n=====memory=====\n");
printf("malloc: %i\n", memory()->malloc_size);
printf("free:   %i\n", memory()->free_size);
printf("================\n\n");*/
void	__destroy_terminal(char *msg)
{
	(void) msg;
	if (terminal()->cmds)
		array(terminal()->cmds)->destroy();
	if (terminal()->envp)
		hashmap(terminal()->envp)->destroy();
	free_list(terminal()->envp_to_str);
	rl_clear_history();
	array(terminal()->history)->destroy();
	printf("%s", msg);
	exit(0);
}
