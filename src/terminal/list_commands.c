/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 23:07:03 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/12 21:03:13 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>
#include <ft_command_util.h>
#include <termios.h>

static t_command	*get_cmd1(char *s)
{
	if (string().equals(s, ">"))
		return (new_redirect_output());
	if (string().equals(s, "<"))
		return (new_redirect_input());
	if (string().equals(s, "cd"))
		return (new_cd());
	if (string().equals(s, "echo"))
		return (new_echo());
	if (string().equals(s, "pwd"))
		return (new_pwd());
	if (string().equals(s, "env"))
		return (new_env());
	if (string().equals(s, "export"))
		return (new_export());
	if (string().equals(s, "minishell"))
		return (new_minishell());
	if (string().equals(s, "unset"))
		return (new_unset());
	return (NULL);
}

t_command	*__get_cmd(char *s)
{
	t_command	*c;

	c = get_cmd1(s);
	if (c)
		return (c);
	if (string().equals(s, "history"))
		return (new_history());
	if (string().equals(s, "exit"))
		return (new_exit());
	if (string().equals(s, ">>"))
		return (new_redirect_output_append());
	if (string().equals(s, "&&"))
		return (new_operator_and());
	if (string().equals(s, "||"))
		return (new_operator_or());
	return (new_command());
}
