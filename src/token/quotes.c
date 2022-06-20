/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:45:31 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/20 18:15:49 by amaria-m         ###   ########.fr       */
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

static int	is_to_sep(const char *str, int i)
{
	if (ft_separator(str) == (i + 1) && !is_quotes(str, i))
		return (1);
	if (string().is_space(str[i]) && !is_quotes(str, i))
		return (1);
	return (0);
}

int	is_sep(const char *str)
{
	if (string().contains(str, "||"))
		return (D_PIPE);
	else if (string().contains(str, "|"))
		return (PIPE);
	else if (string().contains(str, "&&"))
		return (D_AND);
	else if (string().contains(str, "&"))
		return (AND);
	else if (string().contains(str, ">>"))
		return (D_SHIFT_RIGHT);
	else if (string().contains(str, ">"))
		return (SHIFT_RIGHT);
	else if (string().contains(str, "<<"))
		return (D_SHIFT_LEFT);
	else if (string().contains(str, "<"))
		return (SHIFT_LEFT);
	else
		return (NO_SEP);
}

void	*ft_divide_quotes(const char *str)
{
	void	*list;
	int		i;

	list = new_array();
	while (str && *str)
	{
		i = 0;
		while (str[i] && !is_to_sep(str, i))
			i++;
		while (string().is_space(str[i]) && !is_quotes(str, i))
			i++;
		if (!str_isspace(str, i))
			(array(list))->add(string().copy_n(str, i));
		str += i;
		i = ft_sep_move(str);
		if (!str_isspace(str, i))
			(array(list))->add(string().copy_n(str, i));
		str += i;
	}
	return (list);
}

void	*ft_divide_cmds(void *list, int i, int check)
{
	void		*cmds;
	void		*token;
	char		*str;

	token = new_array();
	while (i < array(list)->size)
	{
		check = 0;
		cmds = new_array();
		str = array(list)->get(i);
		while (str && is_sep(str) && \
		!is_quotes(str, ft_separator(str) - 1) && !check)
		{
			if (is_sep(str) != PIPE || array(cmds)->size)
				array(cmds)->add(string().trim(str));
			if (is_sep(str) == D_PIPE || is_sep(str) == D_AND)
				check = 1;
			str = array(list)->get(++i);
		}
		while (str && (!is_sep(str) || is_quotes(str, ft_separator(str) - 1)) \
		&& !check && array(cmds)->add(string().trim(str)))
			str = array(list)->get(++i);
		array(token)->add(cmds);
	}
	array(token)->for_each(set_fun_destroy_token, NULL);
	return (token);
}
