# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 19:07:24 by willda-s          #+#    #+#              #
#    Updated: 2025/05/12 17:02:11 by willda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INCLUDE = -Iincludes

BUILTINS_DIR = builtins/

BUILTINS_FILES =	ft_pwd.c\
					ft_env.c\
					ft_exit.c\
					ft_echo.c\
					ft_cd.c\
					ft_export.c\
					ft_unset.c\
					exec_builtins.c\
					main_builtins.c

UTILS =

MAKEFLAGS += --no-print-directory

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -MMD -g3

FILE =	$(addprefix $(BUILTINS_DIR), $(BUILTINS_FILES))\
		$(UTILS)
		
OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(FILE:.c=.o))
DEPD = $(addprefix $(OBJ_DIR), $(FILE:.c=.d))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: banner lib $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) -lreadline $(OBJ) -o $(NAME) $(LIBFT)
		@echo "$(PURPLE)👾 Minishell compilation done ! $(RESET)"

$(OBJ_DIR)%.o: %.c Makefile
			@mkdir -p $(dir $@)
			@echo "$(YELLOW) Compiling ... $(BLUE)$(notdir $<) $(RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPD)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:	clean
	$(MAKE) -C $(LIBFT_DIR) fclean	
	rm -f $(NAME)      

lib:
	@echo "$(GREEN)🦀 Compiling libft in progress... $(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)🦀 Libft compilation done ! $(RESET)"
	@echo "$(PURPLE)👾 Compiling Minishell in progress ... $(RESET)"

re: fclean all

banner:
	@clear
	@echo "$(GREEN_DARKER)▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌$(RESET)"
	@echo "$(GREEN_DARKER)▐                                                      ▌$(RESET)"
	@echo "$(GREEN_DARKER)▐    $(GREEN_LIGHT)• ▌ ▄ ·. ▪   ▐ ▄ ▪  .▄▄ ·  ▄ .▄▄▄▄ .▄▄▌  ▄▄▌     $(GREEN_DARKER) ▌$(RESET)"
	@echo "$(GREEN_DARKER)▐    $(GREEN_LIGHT)·██ ▐███▪██ •█▌▐███ ▐█ ▀. ██▪▐█▀▄.▀·██•  ██•     $(GREEN_DARKER) ▌$(RESET)"
	@echo "$(GREEN_DARKER)▐    $(GREEN_LIGHT)▐█ ▌▐▌▐█·▐█·▐█▐▐▌▐█·▄▀▀▀█▄██▀▐█▐▀▀▪▄██▪  ██▪     $(GREEN_DARKER) ▌$(RESET)"
	@echo "$(GREEN_DARKER)▐    $(GREEN_LIGHT)██ ██▌▐█▌▐█▌██▐█▌▐█▌▐█▄▪▐███▌▐▀▐█▄▄▌▐█▌▐▌▐█▌▐▌   $(GREEN_DARKER) ▌$(RESET)"
	@echo "$(GREEN_DARKER)▐    $(GREEN_LIGHT)▀▀  █▪▀▀▀▀▀▀▀▀ █▪▀▀▀ ▀▀▀▀ ▀▀▀ · ▀▀▀ .▀▀▀ .▀▀▀    $(GREEN_DARKER) ▌$(RESET)"
	@echo "$(GREEN_DARKER)▐                                                      ▌$(RESET)"
	@echo "$(GREEN_DARKER)▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌$(RESET)"

.PHONY: all clean fclean re lib banner

.SILENT:

BLUE = \033[34m
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m
BOLD = \033[1m
GREEN_DARKER = \033[2;32m
GREEN_LIGHT = \033[;32m
RESET = \033[0m
PURPLE = \033[35m