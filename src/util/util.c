/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/11 19:30:16 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pipex.h>

char	*get_path(t_command	*c, char *arg, const char *path)
{
	int		i[2];

	i[0] = 0;
	path = path + 5;
	while (path && *path)
	{
		i[1] = 0;
		c->path[i[0]] = *path++;
		if (c->path[i[0]] && c->path[i[0]] != ':' && i[0]++ < 100)
			continue ;
		c->path[i[0]++] = '/';
		while (arg && arg[i[1]] && arg[i[1]] != ' ' && arg[i[1]] != '\t')
			c->path[i[0]++] = arg[i[1]++];
		c->path[i[0]] = 0;
		if (access(c->path, F_OK) == -1)
			i[0] = 0;
		else
			break ;
	}
	if (access(c->path, F_OK) == -1)
		c->path[0] = 0;
	return (NULL);
}

int	next_command(t_command *previou, t_command *this)
{
	if (this && this->next && this->next->input)
	{
		terminal()->check_command_args(this->next);
		this->next->input(this, this->next);
	}
	if (previou)
	{
		close(previou->fd[0]);
		close(previou->fd[1]);
	}
	return (1);
}

char	*read_all(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*str;
	char	*temp;
	int		size;

	temp = NULL;
	str = NULL;
	if (fd == -1 || read(fd, buffer, 0) == -1)
		return (NULL);
	while (1)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size > 0)
		{
			buffer[size] = 0;
			temp = str;
			str = string().join(temp, buffer);
			free_ob(temp);
		}
		else
			break ;
	}
	return (str);
}

void	print_msg_error(t_command *this, char *msg, int args)
{
	if (!this || !this->commands || !*this->commands)
		return ;
	if (args == 2)
		printf("bash: %s: %s: %s\n", this->commands[0], this->commands[1], msg);
	if (args == 1)
		printf("bash: %s: %s\n", this->commands[0], msg);
	terminal()->is_erro_cmd = 1;
}

char	*_str(const char c)
{
	static char	str[2];

	str[0] = c;
	return (str);
}
