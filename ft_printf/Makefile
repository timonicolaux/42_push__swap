NAME = libftprintf.a
CC = cc
LIB = ft_printf.h
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c print_char.c print_str.c print_num.c print_unsigned.c print_hex.c print_pointer.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

%.o: %.c $(LIB)
	$(CC) $(FLAGS) -c -I${LIBFT_PATH} $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB) ./libft/*.c
		cd ${LIBFT_PATH} && make && cp libft.a ../${NAME}
		ar rcs $(NAME) $(OBJ)
		ranlib ${NAME}

clean:
	cd ${LIBFT_PATH} && make clean && cd ..
	rm -f ${OBJ}

fclean: clean
	cd ${LIBFT_PATH} && make fclean && cd ..
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re libft
