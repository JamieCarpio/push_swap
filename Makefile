NAME = push_swap

LIB_NAME = libft/lib.a
LIB_PRINTF_NAME = ft_printf/ft_printf.a

CC = cc
AR = ar rcs
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
	ftalg_adaptive.c \
	ftalg_bubble.c \
	ftalg_chunk.c \
	ftalg_radix.c \
	ft_benchmark.c

LIBFT_SRC = libft/ft_*.c
FT_PRINTF_SRC = ft_printf/ft_*.c

OBJ = $(SRC:.c=.o)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

all: $(LIB_NAME) $(LIB_PRINTF_NAME) $(NAME)

$(LIB_NAME): $(LIBFT_OBJ)
	$(AR) $(LIB_NAME) $(LIBFT_OBJ)

$(LIB_PRINTF_NAME): $(FT_PRINTF_OBJ)
	$(AR) $(LIB_PRINTF_NAME) $(FT_PRINTF_OBJ)

$(NAME): $(OBJ) $(LIB_NAME) $(LIB_PRINTF_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_NAME) $(LIB_PRINTF_NAME) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIBFT_OBJ) $(FT_PRINTF_OBJ)

fclean: clean
	rm -f $(NAME) $(LIB_NAME) $(LIB_PRINTF_NAME)

re: fclean all

.PHONY: all clean fclean re