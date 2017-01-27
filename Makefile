# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: varichar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 13:41:20 by varichar          #+#    #+#              #
#    Updated: 2017/01/27 16:55:12 by varichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)
NAME = fdf
HEADER = -Iincludes -Ilib/includes
SRCS_P := $(shell ls srcs/*.c)
SRCS := $(addprefix srcs/, $(SRCS_P))
CFLAGS = -Wall -Werror -Wextra
LIB = -Llib -lft
CC = gcc
OBJ := $(SRCS_P:.c=.o)
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m
ifeq ($(UNAME), Darwin)
	MACOS_VER := $(shell sw_vers | grep ProductVersion |\
		sed s/ProductVersion:\	//g | cut -f1,2 -d'.')
endif

.PHONY: all fclean clean re lib minilibx cleanlibx cleanlib OBJ

all: $(NAME)

$(NAME): minilibx lib $(OBJ)
	@echo "$(GREEN)[✓]$(NC) Objects of $(NAME) compiled"
	@$(CC) -o $@ $(HEADER) $(CFLAGS) $(LIB) $(OBJ) 
	@echo "$(GREEN)[✓]$(NC) library $(NAME) built"

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(HEADER) 

ifeq ($(UNAME), Darwin)

ifeq ($(MACOS_VER), 10.12)

LIB += -Lminilibx_macos_sierra -lmlx -framework OpenGL -framework AppKit
HEADER += -Iminilibx_macos_sierra/

minilibx:
	@make -C minilibx_macos_sierra

cleanlibx:
	@make -C minilibx_macos_sierra clean

endif

ifeq ($(MACOS_VER), 10.11)

LIB += -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
HEADER += -Iminilibx_macos/

minilibx:
	@make -C minilibx_macos

cleanlibx:
	@make -C minilibx_macos clean

endif

endif

ifeq ($(UNAME), Linux)

LIB += -Lminilibx -lmlx -lXext -lX11
HEADER += -Iminilibx/

minilibx:
	@make -C minilibx
	@echo "$(GREEN)[✓]$(NC) library $@ built"

cleanlibx:
	@make -C minilibx clean
	@echo "$(RED)[-]$(NC) Objects of minilibx cleaned"

endif

lib:
	@make -C lib/

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
