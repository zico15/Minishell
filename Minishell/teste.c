/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 17:47:09 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_pipex.h"

void	printf_list(char **s)
{
	int		i;

	if (s)
	{
		i = -1;
		while (s[++i])
			printf("(%s)\n", s[i]);
	}
}

// -fsanitize=address -g
int	main2(int argc, char **argv, char **envp)
{
	//t_terminal	*t;
	(void) argc;
	(void) argv;
	data()->envp = envp;
	data()->teste = 1;
	data()->pid_base = 100;
	/*init_keys();
	new_read_line();
	t = new_terminal("bash-3.2$ ");*/
	//t->input();
	if (argc > 1)
	{
		char *str = string().join("teste ", "casa");
		printf("(%s)\n", str);
		free_ob(str);
	}
	//system("leaks -- minishell");
	return (0);
}
