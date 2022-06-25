/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:43:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/25 10:35:59 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

static char	*check_home_dir(const char *str)
{
	static char	buff[BUFFER_SIZE];
	int			i;
	int			j;

	i = 0;
	j = -1;
	if (!str)
		return (terminal()->home);
	while (str && *str)
	{
		if (i == 0 && string().equals_n(str, "~", 1))
		{
			str++;
			while (terminal()->home[++j])
			{
				buff[i++] = terminal()->home[j];
			}
		}
		buff[i++] = *str++;
	}
	buff[i] = 0;
	return (buff);
}

static int	*ft_input(t_command *previou, t_command *this)
{
	char	buff[BUFFER_SIZE];
	char	*str;
	char	*key_oldpwd;
	int		i;

	i = (!previou->commands || string().equals(*previou->commands, "&&") || \
	(previou->index == __COMMAND_BEGING_));
	if (i && !this->status && this->commands && *this->commands)
	{
		key_oldpwd = string().copy("OLDPWD");
		str = string().copy(getcwd(buff, BUFFER_SIZE));
		(hashmap(terminal()->envp))->put(key_oldpwd, string().copy(str));
		str = check_home_dir(this->commands[1]);
		if (chdir(str) != 0)
			this->status = 1;
		str = string().copy(getcwd(buff, BUFFER_SIZE));
		(hashmap(terminal()->envp))->put(string().copy("PWD"), str);
	}
	if (this->fd[1] != -1)
		close(this->fd[1]);
	return (terminal()->next_command(previou, this));
}

t_command	*new_cd(void)
{	
	t_command	*c;

	c = new_command();
	if (!c)
		return (0);
	c->input = ft_input;
	c->is_real = 0;
	return (c);
}
