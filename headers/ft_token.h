/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:38:03 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/31 16:09:10 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include <ft_pipex.h>

// ft_inside_quotes,
// return 0 -> not quoted ()
// return 1 -> double quoted ("")
// return 2 -> single quoted ('')
// return 4 -> both quoted ("" '') (this is not possible i think)

// FOR ft_inside_quotes FUNCTION
enum quotes {
	NOT_QUOTED,
	DOUBLE_QUOTED,
	SINGLE_QUOTED,
	BOTH_QUOTED,
};

// TOKEN UTILS
char	**ft_exit(void);
int		ft_separator(char l);
int		ft_quotes(char	*letter);
char	**ft_lst_to_arr(void	*tokens);

// QUOTES HANDELING
int		*ft_count_quotes(char *str, int index, int *arr);
int		ft_inside_quotes(char *str, int index);

// TOKEN FUCNTION (returns arr of commands)
char	**token(char *line);

// typedef enum td
// {
// 	IS_PRINT,
// 	NOT_PRINT,
// 	IS_COMMAND,
// 	NOT_COMMAND,
// 	IS_REMOVE,
// 	NOT_REMOVE
// };

#endif