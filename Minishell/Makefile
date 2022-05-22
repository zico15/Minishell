# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/05/22 17:48:03 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	main.c	\
				teste.c	\
				./src/commands/command.c  \
				./src/commands/redirect_input.c \
				./src/commands/redirect_output.c \
				./src/commands/console.c  \
				./src/terminal/terminal.c  \
				./src/terminal/token.c  \
				./src/terminal/read_line.c  \
				./src/terminal/key_controller.c  \
				./src/util/list/list_cmd.c  \
				./src/util/list/list.c  \
				./src/util/string/string.c \
				./src/util/string/string_util.c \
				./src/util/util.c \
				./src/util/this.c \
				./src/util/memory.c \
				./src/util/array/base_array.c \
				./src/util/array/base_array_util.c \

OBJS		= 	$(SRCS:.c=.o)

//CC			= 	gcc -fsanitize=address -g
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	minishell
INCLUDE		= 	./headers

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

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
	make re && clear && ./minishell

.PHONY: all re clean fclean m
