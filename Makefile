# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 10:49:54 by lrocigno          #+#    #+#              #
#    Updated: 2022/02/02 14:24:27 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

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
CFLAGS = -Wall -Werror -Wextra
SANITIZERS = -g3

LIB_PATH = ./lib
LIBFT_PATH = $(LIB_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L./lib/libft -lft

LIBS = $(LIBFT_FLAGS) -lreadline
		
INCLUDES = -I ./lib/libft/includes \
		   -I ./src

vpath %.c src src/env src/prompt src/lexer
SRC := minishell.c get_pwd.c prompt.c interface.c free.c \
	   error.c parse.c get_env.c set_env.c \
	   get_type.c get_value.c helpers.c quote.c tokenizer.c token_new_del.c \

OBJ_PATH = ./build
OBJ := $(addprefix $(OBJ_PATH)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	echo "$$MINISHELL"
	$(CC) $(CFLAGS) $(SANITIZERS) $(INCLUDES) $(OBJ) $(LIBS) -o $@

$(OBJ_PATH)/%.o: %.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(SANITIZERS) $(INCLUDES) $< -c -o $@

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all clean fclean make re
