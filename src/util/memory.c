/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/18 15:11:52 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_util.h>
#include <ft_minishell.h>

int	free_ob(void *v)
{
	if (v == NULL)
		return (1);
	free(v);
	memory()->free_size++;
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

	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		terminal()->destroy(__ERROR_MEMORY_);
	memory()->malloc_size++;
	return (v);
}
