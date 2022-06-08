/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:47:34 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/08 19:33:01 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>
#include <string_util.h>

void	*ft_send_exit(void)
{
	void	*lst;
	void	*cmd;

	lst = new_array();
	cmd = new_array();
	array(cmd)->add(string().copy("exit"));
	array(lst)->add(cmd);
	return (lst);
}

int	ft_separator(const char *str)
{
	int	i;

	i = 0;
	while (str && *str)
	{
		if (string().contains(SEPARADOES, _str(*str++)))
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_rmv_quotes(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*mem;

	if (!str || !*str)
		return (NULL);
	i = -1;
	size = 0;
	while (str[++i])
		if (!(!is_quotes(str, i) && (str[i] == '\"' || str[i] == '\'')))
			size++;
	mem = malloc(sizeof(char) * (size + 1));
	mem[size] = 0;
	i = -1;
	j = 0;
	while (str[++i])
		if (!(!is_quotes(str, i) && (str[i] == '\"' || str[i] == '\'')))
			mem[j++] = str[i];
	free_ob(str);
	return (mem);
}

int	ft_sep_move(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*(str + 1) && str[0] == str[1] && ft_separator(str))
		return (2);
	else if (ft_separator(str))
		return (1);
	else
		return (0);
}
