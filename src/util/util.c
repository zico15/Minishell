/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:01:01 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/15 18:30:55 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell.h>

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

char	*_str(const char c)
{
	static char	str[2];

	str[0] = c;
	return (str);
}

char	**list_commans_bash(void)
{	
	static char	*list[147] = {"ls", "df", "top", "cd", "mkdir", "rm", "cat", \
	"vi", "exit", "logout", "passwd", "rlogin", "ssh", "slogin", \
	"yppasswd", "mail",	"mesg", "pine",	"talk", "write", "apropos", "find", \
	"info", "man", "whatis", "whereis", "emacs", "pico", "sed", "vi", "vim", \
	"cd", "chmod", "chown", "chgrp", "cmp", "comm", "cp", "crypt", "diff", \
	"file", "grep", "gzip", "ln", "lsof", "mkdir", "mv", "pwd", "quota", \
	"rm", "rmdir", "stat", "sync", "sort", "tar", "tee", "tr", "umask", \
	"uncompress", "uniq", "wc", "cat", "fold", "head", "lpq", "lpr", "lprm", \
	"more", "less", "page", "pr", "tail", "zcat", "xv", "gv", "xpdf", "ftp", \
	"rsync", "scp", "netstat", "rsh", "ssh", "nmap", "ifconfig", "ping", \
	"kill", "bg", "fg", "jobs", "top", "clock", "date", "df", "du", "env", \
	"finger", "history", "last", "lpq", "manpath", "printenv", "ps", "pwd", \
	"set", "spend", "uptime", "w", "who", "whois", "whoami", "abiword", "col", \
	"diction", "diffmk", "dvips", "addbib", "explain", "grap", "hyphen", \
	"ispell", "latex", "pdfelatex", "latex2html", "lookbib", "macref", "ndx", \
	"neqn", "nroff", "pic", "psdit", "ptx", "refer", "roffbib", "sortbib", \
	"spell", "style", "tbl", "tex", "tpic", "wget", "html2ps", "latex2html", \
	"lynx", "netscape",	"sitecopy", "weblint", "minishell" };

	return (list);
}
