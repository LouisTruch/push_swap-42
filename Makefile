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
					actions/rotate_a.c \
					actions/rotate_b.c \
					actions/reverse_rotate_a.c \
					actions/reverse_rotate_b.c \
					actions/push_a.c \
					actions/push_b.c \
					algorithm/main_algo.c \
					algorithm/optimisation_and_print.c \
					algorithm/push_pivots_to_b.c \
					algorithm/push_max_to_a.c \
					algorithm/algo_little_sort.c

OBJS_MANDATORY	=	${SRCS_MANDATORY:.c=.o}

NAME_BONUS		=	checker

SRCS_BONUS		=	bonus/checker.c \
					bonus/get_actions.c \
					bonus/check_stacks.c \
					bonus/execute_actions.c \
					bonus/actions/ft_actionlst_functions.c \
					bonus/actions/swap_a.c \
					bonus/actions/swap_b.c \
					bonus/actions/rotate_a.c \
					bonus/actions/rotate_b.c \
					bonus/actions/reverse_rotate_a.c \
					bonus/actions/reverse_rotate_b.c \
					bonus/actions/push_a.c \
					bonus/actions/push_b.c \
					bonus/actions/ss.c \
					bonus/actions/rr.c \
					bonus/actions/rrr.c \
					bonus/parsing/main_parsing.c \
					bonus/parsing/check_functions.c \
					bonus/parsing/make_linked_list.c \
					bonus/parsing/parsing_free_functions.c \
					stack_functions/ft_stacknew.c \
					stack_functions/ft_stacksize.c \
					stack_functions/ft_stacklast.c \
					stack_functions/ft_stackadd_back.c \
					stack_functions/ft_stackadd_front.c \
					stack_functions/ft_stackclear.c \

					

OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

LIB		=	libft/libft.a

CC		= 	clang

CFLAGS	=	-Wall -Wextra -Werror -g 

RM		= 	rm -f

all		:	push_swap libft

bonus	:	checker

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

rebonus	:	fclean bonus

libft	:
		make -C libft

.PHONY	: all clean fclean re bonus rebonus
