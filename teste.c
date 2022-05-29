/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 11:59:25 by edos-san         ###   ########.fr       */
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
	static void	*h;
	char		*key;

	key = "nome";
	h = new_hashmap();
	(hashmap(h))->put(string().copy("oi"), string().copy("HELLO WORD"));
	(hashmap(h))->put(string().copy("casa"), string().copy("HOME"));
	(hashmap(h))->put(string().copy("nome"), string().copy("NAME"));
	printf("size: %i\n", hashmap(h)->size());
	printf("key: %s value: %s\n", key, hashmap(h)->get_key(key)->value);
	hashmap(h)->remove_key("casa");
	printf("size: %i\n", hashmap(h)->size());
	printf("key: %s value: %s\n", key, hashmap(h)->get_key(key)->value);
	hashmap(h)->destroy();
	return (0);
}
//system("leaks -- minishell");
