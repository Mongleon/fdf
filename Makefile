# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 13:41:20 by varichar          #+#    #+#              #
#    Updated: 2017/01/22 17:48:39 by varichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)
NAME = fdf
HEADER = includes
SRCS_P := $(shell ls srcs/)
SRCS := $(addprefix srcs/, $(SRCS_P))
CFLAGS = -Wall -Werror -Wextra -ggdb
CC = gcc
OBJ = $(SRCS:.c=.o)
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m
ifeq ($(UNAME), Darwin)
	MACOS_VER := $(shell sw_vers | grep ProductVersion |\
		sed s/ProductVersion:\	//g | cut -f1,2 -d'.')
endif

.PHONY: all fclean clean re lib minilibx cleanlibx cleanlib

all: $(NAME)

$(NAME): minilibx lib $(OBJ)
	@echo "$(GREEN)[✓]$(NC) Objects of $(NAME) compiled"
	@$(CC) $(CFLAGS) -o $@ -I$(HEADER) $(LIBNAME)
	@echo "$(GREEN)[✓]$(NC) library $(NAME) built"

ifeq ($(UNAME), Darwin)

ifeq ($(MACOS_VER), 10.12)

minilibx:
	@make -C minilibx_macos_sierra

cleanlibx:
	@make -C minilibx_macos_sierra clean

endif

ifeq ($(MACOS_VER), 10.11)

minilibx:
	@make -C minilibx_macos

cleanlibx:
	@make -C minilibx_macos clean

endif

endif

lib:
	@make -C lib/

%.o: %.c
	@$(CC) -c $< -o $@ -I$(HEADER) $(CFLAGS)

clean:
	@rm -Rf $(OBJ)
	@make -C lib clean
	@echo "$(RED)[-]$(NC) Objects of $(NAME) cleaned"

cleanlib:
	@make -C lib fclean
	@echo "$(RED)[-]$(NC) Objects of $(NAME) cleaned"

fclean: clean cleanlib cleanlibx
	@rm -Rf $(NAME)
	@echo "$(RED)[-]$(NC) Library $(NAME) cleaned"

re: fclean all
