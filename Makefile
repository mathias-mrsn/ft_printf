SRCS =	srcs/ft_printf.c \
		srcs/parse.c \
		srcs/parse2.c\
		srcs/print_arg.c \
		srcs/print_flag.c \
		srcs/tools.c \
		srcs/tools2.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = includes

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)


bonus:		all
			

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY:		bonus all clean fclean re