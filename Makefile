# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 10:08:54 by luide-so          #+#    #+#              #
#    Updated: 2023/06/10 11:09:19 by luide-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
NAME = push_swap
BONUS = checker
HEADER = push_swap.h
HEADER_BONUS = checker.h
LIBNAME = libft
LIBDIR = libft/
LIB_FLAGS = -L $(LIBDIR) -lft
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
HDR = -I.

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources to objects

SRC_FILES = push_swap push_swap_utils stack_utils sort sort_utils commands move_nodes error
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))
SRC_BONUS_FILES = checker stack_utils commands error get_next_line get_next_line_utils push_swap_utils
SRC_BONUS = $(addsuffix .c, $(SRC_BONUS_FILES))
OBJ_BONUS = $(addsuffix .o, $(SRC_BONUS_FILES))

# Rules

$(NAME) : $(OBJ) $(HEADER)
	@ make -s bonus -C $(LIBNAME)
	@ echo "$(GREEN)Made $(LIBNAME).a with sucess$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) $(HDR) $(OBJ) $(LIB_FLAGS) -o $(NAME)
	@ echo "$(BLUE)Compiled $(NAME) with sucess!$(DEF_COLOR)"
	@ echo "$(GREEN)Everything is ready to use!$(DEF_COLOR)"
	@ echo "$(YELLOW)Run ./$(NAME) plus numeric argument/s to start$(DEF_COLOR)"

%.o : %.c $(HEADER)
	@ echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) $(HDR) -c $< -o $@
	@ echo "$(GREEN)Object files created with sucess$(DEF_COLOR)"

all : $(NAME)

clean :
	@ $(RM) -rf $(OBJ)
	@ echo "$(RED)Removed $(NAME) object files$(DEF_COLOR)"
	@ ${MAKE} -s clean -C $(LIBNAME)
	@ echo "$(RED)Removed $(LIBNAME) object files$(DEF_COLOR)"

fclean : clean
	@ $(RM)  $(NAME)
	@ echo "$(RED)Removed '$(NAME)' with sucess$(DEF_COLOR)"
	@ $(RM)  $(BONUS)
	@ echo "$(RED)Removed '$(BONUS)' with sucess$(DEF_COLOR)"
	@ ${MAKE} -s fclean -C $(LIBNAME)
	@ echo "$(RED)Removed '$(LIBNAME).a' with sucess$(DEF_COLOR)"
	@ echo "$(RED)Everything clean$(DEF_COLOR)"

re : fclean all

bonus : $(OBJ_BONUS)  $(HEADER_BONUS)
	@ make -s bonus -C $(LIBNAME)
	@ echo "$(GREEN)Made $(LIBNAME).a with sucess$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) $(HDR) $(OBJ_BONUS) $(LIB_FLAGS) -o $(BONUS)
	@ echo "$(BLUE)Compiled $(BONUS) with sucess!$(DEF_COLOR)"
	@ echo "$(GREEN)Everything is ready to use!$(DEF_COLOR)"

.PHONY: all clean fclean re
