/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/31 16:03:53 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_pipex.h>

// -fsanitize=address -g
//open $HOMEBREW_TEMP
//open $TMPDIR  
///tmp/edos-san/Homebrew/Temp
int	main2(void)
{
	char	str[1000];
	scanf("%[^\n]", str);
	int	i = -1;
	while (str[++i])
		printf("str %i: %i\n", i, ft_inside_quotes(str, i));
	return (0);
}
//system("leaks -- minishell");
// "'"'$TERM'"'"
