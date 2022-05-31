/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/31 15:00:59 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_pipex.h>

// -fsanitize=address -g
//open $HOMEBREW_TEMP
//open $TMPDIR  
///tmp/edos-san/Homebrew/Temp
int	main(void)
{
	char	str[1000];
	scanf("%[^\n]", str);
	printf("%i\n", ft_inside_quotes(str, 5));
	return (0);
}
//system("leaks -- minishell");
// "'"'$TERM'"'"
