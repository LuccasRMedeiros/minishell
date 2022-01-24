# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 10:49:54 by lrocigno          #+#    #+#              #
#    Updated: 2022/01/24 16:12:51 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

RED = $(tput setaf 255;0;0)

define MINISHELL
                                                         
                                      .          
                               .     .;          
                               ; .   /.        ; 
                               .\:   ,\      .;| 
                               ;|\_.;|\;._   :|| 
                              ,/;          :;//| 
                            . -               ;| 
                            :/                 \ 
                            |                   |
                            |                   |
                            |                  :|
                             \                ./ 
                              -.     .:      .-  
                                --._:/;:__.--    
  __      __ ____ __   ____ ____   _______ ____ ____ _______  ____     ____    
  \ \    / / \  / \ \  \  / \  /  / _____/ \  / \  / \  ____| \  /     \  /    
   | \  / |   ||   | \  ||   ||   | \___    ||___||   ||__     ||       ||     
   ||\\\//||   ||   ||\\\ ||   ||   \____ \   | ___ |   | __|    ||       ||     
   || \/ ||   ||   || \\\||   ||   ____/ |   ||   ||   ||____   ||____   ||____ 
  /__\  /__\ /__\ /__\ \__\ /__\ /______/  /__\ /__\ /______| /______| /______|
                                
endef
export MINISHELL

CC = clang

FLAGS = -Wall -Werror -Wextra -g

SANITIZERS = 

DEPS =	-lreadline \
		-L ./libs/libft/ -lft \
		
INCLUDES = -I ./libs/libft/ \
		   -I ./includes/ \

BASE =

SRC =

OBJ = $(SRC:%.c=%.o)

SRC_FULL =	$(addprefix ./src/, $(BASE)) \

all: makelibft $(NAME)
	echo $(RED) "$$MINISHELL"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) minishell.c -o $(NAME) $(OBJ) $(DEPS)

$(OBJ): $(SRC_FULL)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) -c $(SRC_FULL)

clean:
	make -C ./libs/libft clean

fclean: clean
	make -C ./libs/libft fclean
	rm -f $(NAME)

re: fclean all

makelibft:
	make -C ./libs/libft all

.PHONY: all clean fclean make re
