# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vischlum <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/19 17:07:58 by vischlum     #+#   ##    ##    #+#        #
#    Updated: 2018/03/15 13:51:15 by vischlum    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	= project

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
INC		= -I inc
SRC_DIR	= src

SRC		= main

OBJ_DIR	= $(SRC_DIR)/objects
OBJ		= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))
LFT		= -L src/lib -lft

all: $(NAME)

$(NAME): $(OBJ)
	@make -C src/lib
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	@make -C src/lib/ clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@make -C src/lib/ fclean
	@/bin/rm -rf $(NAME)

re: fclean all
