/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/13 18:27:39 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_token.h>
#include <ft_base_array_util.h>

static int	str_isspace(const char *str, int size)
{
	int	i;

	i = -1;
	if (!string().size(str) || !size)
		return (1);
	while (++i < size && str[i])
		if (!string().is_space(str[i]))
			return (0);
	return (1);
}

void	*ft_divide_quotes(const char *str)
{
	void	*cmds;
	int		i;

	cmds = new_array();
	i = -1;
	while (str[++i])
	{
		if ((string().is_space(str[i]) || (i == (ft_separator(str) - 1))) \
		&& !is_quotes(str, i))
		{
			if (!str_isspace(str, i))
				(array(cmds))->add(string().copy_n(str, i));
			str += i + !(i == (ft_separator(str) - 1));
			i = ft_sep_move(str);
			if (!(ft_separator(str) - 1))
			{
				(array(cmds))->add(string().copy_n(str, i));
				str += i;
				i = 0;
			}
		}
	}
	if (!str_isspace(str, i))
		(array(cmds))->add(string().copy_n(str, i));
	return (cmds);
}

static void	div_cmd_block(int *check, void **token, void **cmds, char **str)
{
	if (ft_separator(*str))
	{
		if (!*check)
			array(*token)->add(*cmds);
		*cmds = new_array();
		*check = 0;
		if (string().equals(*str, "||") || string().equals(*str, "&&"))
		{
			array(*cmds)->add(string().trim(*str));
			array(*token)->add(*cmds);
			*check = 1;
		}
		else if (!string().equals(*str, "|"))
			array(*cmds)->add(string().trim(*str));
	}
	else if (!*check)
		array(*cmds)->add(string().trim(*str));
}

void	*ft_divide_cmds(void *list)
{
	void		*cmds;
	void		*token;
	char		*str;
	int			i;
	int			check;

	i = -1;
	check = 0;
	cmds = new_array();
	token = new_array();
	while (++i < array(list)->size)
	{
		str = array(list)->get(i);
		div_cmd_block(&check, &token, &cmds, &str);
		if (!ft_separator(str) && check)
		{
			cmds = new_array();
			array(cmds)->add(string().trim(str));
			check = 0;
		}
	}
	array(token)->add(cmds);
	(array(token))->for_each(set_fun_destroy_token, NULL);
	return (token);
}
