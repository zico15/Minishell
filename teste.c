/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/22 18:33:51 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

static int	ft_contains(const char *str, const char *hey)
{
	int	i;
	int	j;
	int	co;

	i = -1;
	co = 0;
	while (str && str[++i] && !co)
	{
		j = 0;
		while (hey && hey[j] && str[i + j] && hey[j] == str[i + j])
		{
			j++;
			if (!hey[j] || !str[i + j])
			{
				co = !hey[j];
				break ;
			}
		}
	}
	return (co);
}

// -fsanitize=address -g
int	main2(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	int i = ft_contains(".", ".");
	printf("(%i)\n", i);
	//system("leaks -- minishell");
	return (0);
}
