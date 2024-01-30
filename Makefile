OBJS_DIR	=	.objs
SRCS_DIR	=	sources
HEADER_DIR	=	includes

SRC		=	$(SRCS_DIR)/algo_utils.c \
			$(SRCS_DIR)/algo.c \
			$(SRCS_DIR)/cost_calculation.c \
			$(SRCS_DIR)/lst_utils.c \
			$(SRCS_DIR)/lst_utils2.c \
			$(SRCS_DIR)/lst_utils3.c \
			$(SRCS_DIR)/main.c $(SRCS_DIR)/push.c $(SRCS_DIR)/reverse.c $(SRCS_DIR)/rotate.c $(SRCS_DIR)/swap.c $(SRCS_DIR)/turk_algo.c

OBJ		=	$(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRC))

NAME	=	push_swap
CC		=	cc
LIB		=	$(HEADER_DIR)/push_swap.h
FLAGS	=	-Wall -Wextra -Werror -I $(HEADER_DIR) -I $(PRINTF_PATH)

PRINTF_PATH = ./ft_printf
PRINTF = ${PRINTF_PATH}/libftprintf.a

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(LIB)
	mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

all: lib $(NAME)

lib:
	make -C $(PRINTF_PATH)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) $(FLAGS) $(PRINTF) -o $(NAME)

clean:
	make clean -C $(PRINTF_PATH)
	rm -f ${OBJ}
	rm -f libftprintf.a

fclean: clean
	make fclean -C $(PRINTF_PATH)
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re ft_printf
