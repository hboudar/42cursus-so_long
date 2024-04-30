SRC = 	get_next_line.c get_next_line_utils.c ft_strlen.c ft_memcpy.c ft_itoa.c\
		ft_strchr.c ft_strrchr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
		ft_printf.c  ft_is_flag.c ft_print_c.c  ft_print_s.c ft_print_p.c  ft_print_x.c ft_print_u.c  ft_print_di.c\
		ft_print_sp.c ft_print_xx.c ft_precision_di.c
OBJS = ${SRC:.c=.o}
LIBC = ar -rcs
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
NAME = libs.a

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} $(OBJS)

fclean: clean
		${RM} ${NAME}

re: fclean all


.PHONY: clean fclean all re
