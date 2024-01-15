NAME = push_swap
CC = cc
LIB = push_swap.h
FLAGS = -Wall -Wextra -Werror
SRC = algo_utils.c algo.c cost_calculation.c lst_utils.c lst_utils2.c lst_utils3.c main.c push.c reverse.c rotate.c swap.c turk_algo.c
OBJ = $(SRC:.c=.o)
PRINTF_PATH = ./ft_printf
PRINTF = ${PRINTF_PATH}/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
		cd ${PRINTF_PATH} && make && cp libftprintf.a ../
		$(CC) $(FLAGS) $(SRC) libftprintf.a -o $(NAME)

clean:
	cd ${PRINTF_PATH} && make clean && cd ..
	rm -f ${OBJ}
	rm -f libftprintf.a

fclean: clean
	cd ${PRINTF_PATH} && make fclean && cd ..
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ft_printf
