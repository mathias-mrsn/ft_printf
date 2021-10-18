SRCS =	srcs/ft_printf.c \
		srcs/parse.c \
		srcs/print_arg.c \
		srcs/tools.c \
		srcs/tools2.c

OBJS = ${SRCS:.c=.o}

SRCSBONUS =	srcs/bonus/ft_printf_bonus.c \
		srcs/bonus/parse_bonus.c \
		srcs/bonus/parse2_bonus.c\
		srcs/bonus/print_arg_bonus.c \
		srcs/bonus/print_flag_bonus.c \
		srcs/bonus/tools_bonus.c \
		srcs/bonus/tools2_bonus.c

OBJSBONUS	= ${SRCSBONUS:.c=.o}
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCS = includes

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)


bonus: ${OBJSBONUS}
			ar -rcs ${NAME} ${OBJSBONUS}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY:		bonus all clean fclean re