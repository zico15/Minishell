# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 18:43:51 by edos-san          #+#    #+#              #
#    Updated: 2022/06/25 19:08:38 by edos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#CC			= 	gcc -fsanitize=address -g
CC			= 	gcc -g
CFLAGS		= 	-Wall -Wextra -Werror
RM			= 	/bin/rm -f
NAME		= 	minishell
INCLUDES	= 	./headers

SRCS		= 	main.c $(shell find src/ -name '*.c')
OBJS		= 	$(SRCS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;32mOBJECT FILES COMPILED\033[0m"
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I /Users/$(USER)/.brew/opt/readline/include -o $(NAME)
	@echo "\033[0;32mMINISHELL IS READY TO USE\033[0m"

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED MINISHELL EXECUTABLE\033[0m"

re: fclean all

norm :
	@norminette -R CheckForbiddenSourceHeader $(SRCS)

m: fclean

v:
	@make re && make clean && clear && valgrind --leak-check=full --log-file="logfile.out" -v ./minishell
e:
	@make re && make clean && clear && valgrind --leak-check=full --track-origins=yes ./minishell
r:
	@make re && make clean && clear && ./minishell

.PHONY: all re clean fclean m
