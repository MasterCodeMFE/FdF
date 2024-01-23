# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manufern <manufern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 18:07:32 by manufern          #+#    #+#              #
#    Updated: 2024/01/17 17:28:30 by manufern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -lmlx -framework OpenGL -framework AppKit

# Target and sources
NAME = fdf
SRCS = src/1_main.c \
       src/2_get_line_map.c \
       src/3_list.c \
       src/4_drow_map.c \
       src/aux.c \
       src/free.c \
       src/ft_atoi.c \
       src/ft_dda.c \
       src/ft_isalpha.c \
       src/ft_isdigit.c \
       src/ft_split.c \
       src/ft_strcpy_to_char.c \
       src/ft_strlen.c \
       src/ft_toupper.c \
       src/get_next_line.c \
       src/get_next_line_utils.c

# Libraries and objects
LIB = ar rcs
OBJS = $(SRCS:.c=.o)

# Colors
RESET = \033[0m
GREEN = \033[32m
RED = \033[31m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)$(RESET)"
	@$(CC) $(LFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Compilation complete$(RESET)"
	@echo "$(GREEN)Displaying image$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)[$(RESET)$(RED)$@$(RESET)$(GREEN)] $(NAME)$(RESET)"

# Clean
clean:
	@echo "$(RED)Removing object files$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean all

# Phony targets
.PHONY: all clean fclean re