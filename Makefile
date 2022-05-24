# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaria-m <amaria-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/05/24 19:12:45 by amaria-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	main.c teste.c $(shell find src/ -name '*.c')

OBJS		= 	$(SRCS:.c=.o)

#CC			= 	gcc -fsanitize=address -g
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	minishell
INCLUDES	= 	./headers

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDES) -Ireadline -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) -I$(INCLUDES) -Ireadline $(OBJS) -o $(NAME)

bonus: all

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader $(SRCS)

m: fclean

r:
	make re && make clean && clear && ./minishell

.PHONY: all re clean fclean m
