## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2022/01/17 10:49:54 by lrocigno          #+#    #+#             ##
##   Updated: 2022/01/25 09:28:29 by vgoncalv         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

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
CFLAGS = -Wall -Werror -Wextra -g
SANITIZERS = 

LIB_PATH = ./lib
LIBFT_PATH = $(LIB_PATH)/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_FLAGS = -L./lib/libft -lft

LIBS = $(LIBFT_FLAGS) -lreadline
		
INCLUDES = -I ./lib/libft/includes \
		   -I ./src

vpath %.c src
SRC :=

OBJ_PATH = ./build
OBJ := $(addprefix $(OBJ_PATH)/,$(SRC:%.c=%.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	echo $(RED) "$$MINISHELL"
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(SANITIZERS) $(INCLUDES) $(OBJ) src/$(NAME).c $(LIBS) -o $@

$(OBJ_PATH)/%.o: %.c
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
