/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/08 22:56:09 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_pipex.h>

int	free_ob(void *v)
{
	if (v)
	{
		free(v);
		memory()->free_size++;
	}
	return (1);
}

int	free_list(char **str)
{
	int		i;

	if (str)
	{
		i = -1;
		while (str[++i])
			free_ob(str[i]);
		free_ob(str);
		return (i);
	}
	return (0);
}

t_memory	*memory(void)
{
	static t_memory	m = {0, 0};

	return (&m);
}

void	*malloc_ob(size_t __size)
{
	void	*v;

	v = malloc(__size);
	if (!v)
		printf("ERROR\n");
	memory()->malloc_size++;
	return (v);
}
