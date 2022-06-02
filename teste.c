/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/01 16:52:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_pipex.h>
#include <ft_base_array.h>

static void	p(t_element *e, void *o)
{
	(void) o;
	printf("key: %s  value: %s\n", e->key, e->value);
}
// -fsanitize=address -g
//open $HOMEBREW_TEMP
//open $TMPDIR  
///tmp/edos-san/Homebrew/Temp
int	main2(void)
{
	void	*t;

	t = new_hashmap();
	hashmap(t)->put(string().copy("S0"), string().copy("sfdffdsdfdsfsdS0"));
	hashmap(t)->put(string().copy("S1"), string().copy("sfdffdsdfdsfsdS1"));
	hashmap(t)->put(string().copy("S2"), string().copy("sfdffdsdfdsfsdS2"));
	hashmap(t)->put(string().copy("S3"), string().copy("sfdffdsdfdsfsdS3"));
	hashmap(t)->for_each(p, 0);
	printf("================================================\n");
	hashmap(t)->remove_key("S3");
	hashmap(t)->for_each(p, 0);
	/*t = new_array();
	printf("================================================\n");
	array(t)->add(string().copy("S0"));
	array(t)->add(string().copy("S1"));
	array(t)->add(string().copy("S2"));
	array(t)->add(string().copy("S3"));
	array(t)->for_each(p, 0);
	printf("size: %i\n", array(t)->size);
	printf("================================================\n");
	array(t)->remove_index(0);
	array(t)->remove_index(0);
	array(t)->remove_index(0);
	array(t)->remove_index(0);
	array(t)->for_each(p, 0);
	printf("size: %i\n", array(t)->size);*/
	return (0);
}
//system("leaks -- minishell");
// "'"'$TERM'"'"
