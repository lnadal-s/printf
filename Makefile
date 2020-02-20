SRCS = ./acquisition.c \
	   ./check_utils.c \
	   ./clear.c \
	   ./ft_printf.c \
	   ./linked_list.c \
	   ./printing.c \
	   ./processing.c \
	   ./process_char.c \
	   ./process_p.c \
	   ./process_str.c \
	   ./process_u.c \
	   ./process_x.c \
	   ./process_dec.c \
	   ./specific_case.c \
	   ./utils.c

SRCSBONUS = 

OBJBONUS = ${SRCSBONUS:.c=.o}

HEADER = .

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

LIBFT_DIR = ./libft

GCC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o: %.c libftprintf.h
	${GCC} -I ${HEADER} ${FLAGS} -Ilibft -c $< -o ${<:.c=.o}

$(NAME):  LIB $(OBJS)
		ar -rcs ${NAME} ${OBJS} 
		ranlib ${NAME}

LIB:
		make -C ${LIBFT_DIR} re	
		cp ./libft/libft.a ${NAME}


all:	${NAME}	
		
bonus:		


clean:
		${RM} ${OBJS}
		${RM} ${OBJBONUS}
fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re bonus
