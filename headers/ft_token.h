/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:38:03 by amaria-m          #+#    #+#             */
/*   Updated: 2022/06/24 19:25:34 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include "ft_minishell.h"

# define SEPARADOES "|<>&"

// is_quotes,
// return 0 -> not quoted ()
// return 1 -> double quoted ("")
// return 2 -> single quoted ('')
// return 4 -> both quoted ("" '') (this is not possible i think)

// FOR is_quotes FUNCTION
enum e_quotes {
	NOT_QUOTED,
	DOUBLE_QUOTED,
	SINGLE_QUOTED,
	BOTH_QUOTED,
};

enum e_seps {
	NO_SEP,
	PIPE,
	D_PIPE,
	SHIFT_LEFT,
	SHIFT_RIGHT,
	D_SHIFT_LEFT,
	D_SHIFT_RIGHT,
	AND,
	D_AND,
};

// TOKEN UTILS
void	*ft_send_exit(void);
int		ft_separator(const char *str);
void	*ft_divide_cmds(void *list, int i, int check);
int		ft_sep_move(const char *str);
void	set_fun_destroy_token(t_element *e, void *o);
void	command_destroy_element(t_element	*e);
int		is_sep(const char *str);

// QUOTES HANDELING
int		is_quotes(const char *str, int index);
char	*ft_rmv_quotes(char *str);
void	*ft_divide_quotes(const char *str);

// TOKEN FUCNTION (returns arr of commands)
void	*token(char *line);

// Brackets handeling

int		ft_handle_brackets(const char *str, int index);

typedef struct s_token
{
	void	*list;
}		t_token;

#endif
