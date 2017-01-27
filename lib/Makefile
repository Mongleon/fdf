# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 13:41:20 by varichar          #+#    #+#              #
#    Updated: 2017/01/24 08:38:27 by varichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = includes
SRCS_P = $(shell ls srcs/)
SRCS = $(addprefix srcs/, $(SRCS_P))

CFLAGS = -Wall -Werror -Wextra -ggdb
CC = gcc

OBJ = $(SRCS:.c=.o)
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)[✓]$(NC) Objects of $(NAME) compiled"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)[✓]$(NC) library $(NAME) built"

%.o: %.c
	@$(CC) -c $< -o $@ -I$(HEADER) $(CFLAGS)

clean:
	@rm -Rf $(OBJ)
	@echo "$(RED)[-]$(NC) Objects of $(NAME) cleaned"

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(RED)[-]$(NC) Library $(NAME) cleaned"

re: fclean all
