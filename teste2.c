/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:29:37 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/29 16:02:09 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ft_string.h>

// -fsanitize=address -g
//open $HOMEBREW_TEMP
//open $TMPDIR  
///tmp/edos-san/Homebrew/Temp

char *remove_quotes_duplo_all(const char *str, char c)
{
	char new[999999];
	int i = 0;
	while (str && *str)
	{
		if (*str != c)
			new[i++] = *str;
		str++;
	}
	new[i] = 0;
	return (string().copy(new));
}

char *remove_quotes_duplo(const char *str, char c)
{
	char new[999999];
	int i = 0;
	int j = 1;
	while (str && *str)
	{
		if (*str != c)
		{
			new[i++] = *str;
			j = 1;
		}
		else if (j)
		{
			new[i++] = *str;
			j = 0;
		}
		str++;
	}
	new[i] = 0;
	return (string().copy(new));
}

int check_quotes(char *str, int i, char c)
{
	int index = -1;
	int is_beging = 0;
	int is_end = 0;
	int size = string().size(str);
	if (str[i] == c)
		return (-1);
	while (++index < i)
	{
		if (str[index] == c && (index - 1 >= 0 || str[index - 1] != c))
			is_beging++;
	}
	is_beging = ((double) is_beging / 2) != (is_beging / 2);
	while (++i < size)
	{
		if (str[i] == c && str[i + 1] != c)
			is_end++;
	}
	is_end = ((double) is_end / 2) != (is_end / 2);
	return (is_beging * is_end);
}

int	main3(void)
{
	int i = -1;
	char *str = "echo \"'\"\'$TERM\'\"'\"";
	str = remove_quotes_duplo(str, '"');
	//str = remove_quotes_duplo_all(str, '"');
	int size = string().size(str);
	printf("================================\n");
	printf("str: %s\n", str);
	printf("================================\n");
	while (++i < size)
	{
		printf("%i_check_quotes: %i (%c)\n",i,  check_quotes(str, i, '"'), str[i]);
	}
	
	printf("================================\n");
	printf("================================\n");
	i = -1;
	while (++i < size)
	{
		printf("%i_check_quotes: %i (%c)\n",i,  check_quotes(str, i, '\''), str[i]);
	}
	
	printf("================================\n");
	printf("%s\n", str);
	return (1);
}
//system("leaks -- minishell");
