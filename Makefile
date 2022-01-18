# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 10:49:54 by lrocigno          #+#    #+#              #
#    Updated: 2022/01/18 16:01:33 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

define MINISHELL
                                                         
                                    
                                     .          
                              .     .:          
                              ; .   ;.        ; 
                              .\:   ,;      .;| 
                              ;|\__;;\;_.   :|| 
                             ,/;          :;//| 
                           . -               ;| 
                           :/                 \ 
                           |                   |
                           |                   |
                           |                  :|
                            \                ./ 
                             -.     .:      .-  
                               --..:/;:...--    
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

DEPS = -lreadline

INCLUDES =

BASE =

SRC =

OBJ = $(SRC:%.c=%.o)

SRC_FULL =	$(addprefix ./src/, $(BASE)) \

all: $(NAME)
	echo "$$MINISHELL"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) minishell.c -o $(NAME) $(OBJ) $(DEPS)

$(OBJ): $(SRC_FULL)
	$(CC) $(FLAGS) $(SANITIZERS) $(INCLUDES) -c $(SRC_FULL)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
