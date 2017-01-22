# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 13:41:20 by varichar          #+#    #+#              #
#    Updated: 2017/01/22 15:47:15 by varichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBNAME = libft.a
HEADER = includes
SRCS_P = $(shell ls srcs/)
SRCS_L = $(shell ls lib/)
LIB = $(addprefix lib/, $(SRCS_L))

CFLAGS = -Wall -Werror -Wextra -ggdb
CC = gcc

OBJ = $(SRCS:.c=.o)
LIBOBJ = $(LIB:.c=.o)
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBNAME)
	@echo "$(GREEN)[✓]$(NC) Objects of $(NAME) compiled"
	$(CC) $(CFLAGS) -o $@ -I$(HEADER) $(LIBNAME)
	@echo "$(GREEN)[✓]$(NC) library $(NAME) built"

$(LIBNAME): $(LIBOBJ)
	@echo "$(GREEN)[✓]$(NC) Objects of $(NAME) compiled"
	@ar rc $(LIBNAME) $(LIBOBJ)
	@ranlib $(LIBNAME)
	@echo "$(GREEN)[✓]$(NC) library $(NAME) built"

%.o: %.c
	@$(CC) -c $< -o $@ -I$(HEADER) $(CFLAGS)

clean:
	@rm -Rf $(OBJ) $(LIBOBJ)
	@echo "$(RED)[-]$(NC) Objects of $(NAME) cleaned"

cleanlib:
	@rm -Rf $(LIBNAME)
	@echo "$(RED)[-]$(NC) Objects of $(NAME) cleaned"

fclean: clean cleanlib
	@rm -Rf $(NAME)
	@echo "$(RED)[-]$(NC) Library $(NAME) cleaned"

re: fclean all
