CC := cc
CFLAGS := -Wextra -Wall -Werror

NAME := libftprintf.a

AR := ar rcs

RM := rm -f

SRCS := ft_printf.c ft_printf_utils.c handle_s.c handle_s_bonus.c ft_printf_utils_bonus.c handle_p.c handle_d.c handle_u.c handle_x.c

OBJ := ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${AR} $@ $?

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

bonus: ${NAME}

clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re