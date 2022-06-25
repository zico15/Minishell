/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_minishell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/24 21:00:30 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static int	list_colores(char *str, char **temp, int i)
{
	if (string().contains(str, "=") && terminal()->color)
	{
		temp = string().split(str, "=");
		i = string().atoi(temp[1]);
		if (!(i >= 0 && i <= 16))
			return (free_list(temp) + printf("invalid color!\n"));
		terminal()->color[2] = ((i > 9) + '0');
		terminal()->color[5] = ((i % 10) + '0');
		return (free_list(temp));
	}
	printf("\033[0;30m 0 -  Preto\033[0m\n\033[0;31m 1 -  Vermelho  \033[0m\n");
	printf("\033[0;32m 2 -  Verde\033[0m\n\033[0;33m 3 -  Marrom  \033[0m\n");
	printf("\033[0;34m 4 -  Azul\033[0m\n\033[0;35m 5 -  Purple  \033[0m\n");
	printf("\033[0;36m 6 -  Cyan\033[0m\n\033[0;37m 7 -  Cinza Claro  \033[0m\n");
	printf("\033[1;30m 10 - Preto Acinzentado\033[0m\n");
	printf("\033[1;31m 11 - Vermelho Claro\033[0m\n");
	printf("\033[1;32m 12 - Verde Claro\033[0m\n");
	printf("\033[1;33m 13 - Amarelo\033[0m\n\033[1;34m 14 - Azul  Claro\033[0m\n");
	printf("\033[1;35m 15 - Purple Claro\033[0m\n");
	printf("\033[1;36m 16 - Cyan  Claro\033[0m\n");
	printf("\033[1;37m 17 - Branco\033[0m\n");
	return (printf(" SET COLOR (color=number)\n"));
}

static int	load_tester(t_command *this)
{
	char	**l;

	l = string().split(this->commands[1], "=");
	if (l && *l)
		(terminal()->fd_test) = open(l[1], O_RDONLY);
	free_list(l);
	return (1);
}

static int	*ft_input(t_command *previou, t_command *this)
{
	int	print;

	print = 0;
	if (string().size_list(this->commands) > 1)
	{
		if (string().equals_n(this->commands[1], "color", 5))
			print = list_colores(this->commands[1], NULL, 0);
		else if (string().equals_n(this->commands[1], "tester=", 7))
			print = load_tester(this);
	}
	if (!print)
	{
		printf("===========minishell===========\n");
		printf("shlvl: %i\n", terminal()->shlvl);
		printf("pid: %i\n", terminal()->pid);
		printf("pid parent: %i\n", terminal()->pid_parent);
		printf("created by: %s\n", CREATED_1);
		printf("created by: %s\n", CREATED_2);
		printf("===========================\n");
	}
	if (this->fd[1] != -1)
		close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_minishell(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	c->is_real = 0;
	return (c);
}

char	*__get_title(void)
{
	static char	buff[BUFFER_SIZE];
	char		*color_end;
	int			i;
	int			j;

	i = 0;
	j = -1;
	color_end = "\033[0m ";
	while (terminal()->color && terminal()->color[++j])
		buff[i++] = terminal()->color[j];
	j = -1;
	while (terminal()->title && terminal()->title[++j])
		buff[i++] = terminal()->title[j];
	j = -1;
	while (color_end[++j])
		buff[i++] = color_end[j];
	buff[i] = 0;
	return (buff);
}
