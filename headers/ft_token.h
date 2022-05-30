/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:38:03 by amaria-m          #+#    #+#             */
/*   Updated: 2022/05/30 17:14:22 by amaria-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# include <ft_pipex.h>

// TOKEN UTILS
char	**ft_exit(void);
int		ft_separator(char l);
int		ft_quotes(char	*letter);
char	**ft_lst_to_arr(void	*tokens);

// QUOTES HANDELING WHITHOUT $ SIGN
void	ft_handle_quotes(void *tokens);
int		*ft_count_quotes(char *str, int index, int *arr);

// TOKEN FUCNTION (returns arr of commands)
char	**token(char *line);

#endif