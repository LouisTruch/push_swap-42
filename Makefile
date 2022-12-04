NAME_MANDATORY	=	push_swap

SRCS_MANDATORY	=	push_swap.c	\
					stack_functions/ft_stacknew.c \
					stack_functions/ft_stacksize.c \
					stack_functions/ft_stacklast.c \
					stack_functions/ft_stackadd_back.c \
					stack_functions/ft_stackadd_front.c \
					stack_functions/ft_stackclear.c \
					parsing/main_parsing.c \
					parsing/check_functions.c \
					parsing/make_linked_list.c \
					parsing/parsing_free_functions.c \
					actions/swap_a.c \
					actions/swap_b.c \
					actions/ss.c \
					actions/rotate_a.c \
					actions/rotate_b.c \
					actions/rr.c \
					actions/reverse_rotate_a.c \
					actions/reverse_rotate_b.c \
					actions/rrr.c \
					actions/push_a.c \
					actions/push_b.c

OBJS_MANDATORY	=	${SRCS_MANDATORY:.c=.o}

NAME_BONUS		=	
SRCS_BONUS		=	
OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

LIB		=	libft/libft.a

CC		= 	clang

CFLAGS	=	-g -Wall -Wextra -Werror

RM		= 	rm -f

all		:	push_swap libft

bonus	:

.c.o	:	${CC} ${CFLAGS} -c $ -o ${<:.c=.o}

${NAME_MANDATORY}	:	${OBJS_MANDATORY}
		make -C libft
		${CC} ${CFLAGS} -o ${NAME_MANDATORY} ${OBJS_MANDATORY} ${LIB}

${NAME_BONUS}		:	${OBJS_BONUS}
		make -C libft
		${CC} ${CFLAGS} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIB}

clean	:
		make -C libft clean
		${RM} ${OBJS_MANDATORY} ${OBJS_BONUS}

fclean	:
		make -C libft fclean
		${RM} ${NAME_MANDATORY} ${OBJS_MANDATORY} ${NAME_BONUS} ${OBJS_BONUS}

re		:	fclean all

libft	:
		make -C libft

.PHONY	: all clean fclean re bonus
