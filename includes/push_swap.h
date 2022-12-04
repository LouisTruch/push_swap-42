/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:05:26 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/04 16:13:10 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define RED "\033[1;31m"
# define NC "\033[0m"

typedef struct s_stack
{
	int					nb;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

/* Parsing functions                                                          */

t_stack			*parse_arguments(char **av);
char			*join_argv(char **av);
int				check_characters(char *str);
int				check_overflow(char **array_str);
int				check_duplicates(char **array_str);

void			ft_print_error_exit(void);
void			ft_free_array_str(char **array_str);

t_stack			*create_linked_list(char **array_str);
t_stack			*ft_stacknew(int nb);
unsigned int	ft_stacksize(t_stack *stack);
void			ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack			*ft_stacklast(t_stack *stack);
void			ft_stackadd_back(t_stack **stack, t_stack *new);
void			ft_stackclear(t_stack **stack);

t_stack			*normalize_stack_nb(t_stack *stack);
void			bubble_sort(int	*int_stack, int size);
t_stack			*stack_copy(t_stack *stack);
t_stack			*make_normalized_stack(t_stack *stack, int *int_stack);

void			swap_a(t_stack *stack);
void			swap_b(t_stack *stack);
void			ss(t_stack *stack_a, t_stack *stack_b);
void			rotate_a(t_stack *stack);
void			rotate_b(t_stack *stack);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate_a(t_stack *stack);
void			reverse_rotate_b(t_stack *stack);
void			rrr(t_stack *stack_a, t_stack *stack_b);
void			push_a(t_stack **stack_b, t_stack **stack_a);
void			push_b(t_stack **stack_a, t_stack **stack_b);

#endif
