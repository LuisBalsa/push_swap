# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 10:08:54 by luide-so          #+#    #+#              #
#    Updated: 2023/05/31 17:25:43 by luide-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
NAME = push_swap
HEADER = push_swap.h
LIBNAME = libft
LIBDIR = libft/
LIB_FLAGS = -L. -l$(NAME) -L./$(LIBDIR) -lft
CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak -g
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
SRC_FILES = push_swap stack_utils push_swap_utils sort commands
SRC = $(addsuffix .c, $(SRC_FILES))
OBJ = $(addsuffix .o, $(SRC_FILES))

# Rules

$(NAME) : $(OBJ)
	@ make -s bonus -C $(LIBNAME)
	@ echo "$(GREEN)Made $(LIBNAME).a with sucess$(DEF_COLOR)"
	@ $(AR) $(addprefix lib, $(addsuffix .a, $(NAME))) $(OBJ)
	@ echo "$(GREEN)Updated $(addprefix lib, $(addsuffix .a, $(NAME)))$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) $(HDR) $(LIB_FLAGS) -o $(NAME)
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
	@ $(RM) $(NAME)
	@ echo "$(RED)Removed '$(NAME)' with sucess$(DEF_COLOR)"
	@ $(RM) $(addprefix lib, $(addsuffix .a, $(NAME)))
	@ echo "$(RED)Removed '$(addprefix lib, $(addsuffix .a, $(NAME)))' with sucess$(DEF_COLOR)"
	@ ${MAKE} -s fclean -C $(LIBNAME)
	@ echo "$(RED)Removed '$(LIBNAME).a' with sucess$(DEF_COLOR)"
	@ echo "$(RED)Everything clean$(DEF_COLOR)"

re : fclean all

# bonus:

.PHONY:		all clean fclean re
