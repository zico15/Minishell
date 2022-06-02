/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_teste.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 18:55:03 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

static int	*ft_input(t_command *previou, t_command *this)
{
	char		*str1;
	char		*str2;

	if (string().size_list(this->commands) < 3)
		return (this->fd);
	str1 = this->commands[1];
	str2 = this->commands[2];
	printf("===========TESTE===========\n");
	printf("isalnum: %i\n", string().isalnum('c'));
	printf("str1: %s str2: %s\n", str1, str2);
	printf("contains: %i\n", string().contains(str1, str2));
	printf("replace: %s\n", string().replace(str1, "(KKKK)", str2));
	printf("get_exts: %s\n", terminal()->get_exts(str1));
	printf("wildcards: \n%s\n", terminal()->wildcards(str1));
	printf("===========================\n");
	next_command(previou, this);
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
