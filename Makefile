# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/05/25 20:20:21 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	main.c teste.c $(shell find src/ -name '*.c')

OBJS		= 	$(SRCS:.c=.o)

CC			= 	gcc -fsanitize=address -g
#CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	minishell
INCLUDES	= 	./headers

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) -I$(INCLUDES) -lreadline $(OBJS) -o $(NAME)

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
	@make re && make clean && clear && ./minishell

.PHONY: all re clean fclean m
