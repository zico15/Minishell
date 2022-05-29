/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_teste.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 10:41:42 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char		*str;
	char		*str2;

	str = "$PWDabcd  dsds";
	str2 = this->commands[1];
	printf("===========TESTE===========\n");
	printf("quotes: (%s) (%i)\n", str2, ft_quotes(str2));
	printf("contains: %i\n", string().contains(str, "*.c"));
	printf("replace: %s\n", string().replace(str, "KKKK", "$PWD"));
	printf("wildcards: \n%s\n", terminal()->wildcards(this->commands[1]));
	printf("===========================\n");
	next_command(previou, this);
	close(previou->fd[0]);
	close(previou->fd[1]);
	return (this->fd);
}

t_command	*new_teste(char *arg)
{	
	t_command	*c;

	c = new_command(arg);
	if (!c)
		return (0);
	c->input = ft_input;
	return (c);
}
