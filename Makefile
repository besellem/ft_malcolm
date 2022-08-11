# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: besellem <besellem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 16:55:38 by besellem          #+#    #+#              #
#    Updated: 2022/08/11 17:04:02 by besellem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ft_malcolm

## Main directories
BUILD_DIR	:=	.build
LIB_DIR		:= libft
SRCS_DIR	:=	srcs
SUB_DIR		:=	srcs
OBJ_DIR 	:=	$(BUILD_DIR)/obj
DIRS		:=	$(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# flags
IFLAGS		:=	-I incs -I libft/incs
LIBFLAGS 	:=	-L./libft -lft

## Main srcs
SRCS		:=	main.c


## Objects
OBJS 		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)


## Commands
CC			:=	clang
CFLAGS		:=	-Wall -Wextra -Werror -g3 -fsanitize=address #-Wpedantic
RM			:=	rm -f


# Colors
CLR_COLOR	:= \033[0m
RED			:= \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m


## Compilation
$(NAME):	$(OBJS)
			@echo "Compiling $(RED_COLOR)Libft $(DEFAULT_COLOR)..."
			@$(MAKE) -C $(LIB_DIR) >/dev/null 2>&1
			@echo "Creating $(RED_COLOR)$@ $(CLR_COLOR)..."
			@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ $(LIBFLAGS)
			@echo "$(GREEN)Compilation $(YELLOW)of $(RED)$@ $(BLUE)done$(CLR_COLOR)"

all:		$(NAME)

clean:
			@echo "Deleting $(CYAN_COLOR)libft $(DEFAULT_COLOR)objs ..."
			@$(MAKE) clean -C $(LIB_DIR) >/dev/null
			@ echo "Deleting $(CYAN)$(NAME) $(CLR_COLOR)objs ..."
			@ rm -rf $(BUILD_DIR)

fclean:		clean
			@echo "Deleting $(CYAN_COLOR)libft $(DEFAULT_COLOR)library ..."
			@$(MAKE) fclean -C $(LIB_DIR) >/dev/null
			@ echo "Deleting $(CYAN)$(NAME) $(CLR_COLOR)binary ..."
			@ $(RM) $(NAME)

re:			fclean all

$(BUILD_DIR):
			@ echo "Creating $(RED)$@ $(CLR_COLOR)..."
			@ mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRCS_DIR)/%.c | $(BUILD_DIR)
			@ echo "Compiling $(YELLOW)$< $(CLR_COLOR)..."
			@ $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY:		all clean fclean re