# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamie_ubuntu <jamie_ubuntu@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 18:01:44 by jacarpio          #+#    #+#              #
#    Updated: 2026/03/20 20:47:27 by jamie_ubunt      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	main.c \
	ft_atol.c \
	ft_isdigit.c \
	ft_is_number.c \
	ft_strcmp.c \
	ft_check_input.c \
	ft_stack_size.c \
	ft_init_stack.c \
	ft_index_stack.c \
	ft_free_stack.c \
	ft_disorder.c \
	ft_duplicates.c \
	ft_is_sorted.c \
	ft_swap.c \
	ft_push.c \
	ft_rotate.c \
	ft_revrotate.c \
	ftalg_adaptative.c \
	ftalg_bubble.c \
	ftalg_chunk.c \
	ftalg_radix.c \
	ft_benchmark.c
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lm -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re