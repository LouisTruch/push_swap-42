/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:05:26 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 11:47:14 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int					nb;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

/* Parsing functions                                                          */

t_stack		*parse_arguments(char **av);
char		*join_argv(char **av);
int			check_characters(char *str);
int			check_overflow(char **array_str);
int			check_for_empty_array(char **array_str);
void		check_duplicates(t_stack **stack_a);
void		ft_free_array_str(char **array_str);
void		ft_print_error_exit(void);

/* Linked lists functions                                                     */

t_stack		*create_linked_list(char **array_str);
t_stack		*ft_stacknew(int nb);
size_t		ft_stacksize(t_stack *stack);
void		ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *new);
void		ft_stackclear(t_stack **stack);

/* Normalizing functions                                                      */

t_stack		*normalize_stack_nb(t_stack *stack);
void		bubble_sort(int	*int_stack, int size);
t_stack		*stack_copy(t_stack *stack);
t_stack		*make_normalized_stack(t_stack *stack, int *int_stack);

/* Stack actions functions                                                    */

void		swap_a(t_stack *stack_a, t_list **lst);
void		swap_b(t_stack *stack_b, t_list **lst);
void		rotate_a(t_stack *stack, t_list **lst);
void		rotate_b(t_stack *stack, t_list **lst);
void		reverse_rotate_a(t_stack *stack, t_list **lst);
void		reverse_rotate_b(t_stack *stack, t_list **lst);
void		push_a(t_stack **stack_b, t_stack **stack_a, t_list **lst);
void		push_b(t_stack **stack_a, t_stack **stack_b, t_list **lst);

/* Main algorithm functions                                                   */

void		main_algorithm(t_stack **stack_a, t_stack **stack_b, t_list **lst);
void		push_by_pivot(t_stack **stack_a,
				t_stack **stack_b, t_list **lst, int max_pivot);
int			find_closest_to_push(t_stack **stack_a, int max_pivot);
void		push_closest_to_b(t_stack **stack_a,
				t_stack **stack_b, t_list **lst, int way);
int			check_list_max_pivot(t_stack **stack_a, int max_pivot);
void		push_max_to_a(t_stack **stack_a, t_stack **stack_b, t_list **lst);
int			find_shortest_to_max(t_stack **stack_b, int max);
void		put_max_on_top(t_stack **stack_b, t_list **lst, int way);
int			find_max_in_stack(t_stack **stack_b);

/* Algorithms functions for 5 or less elements                                */

void		algo_little_sort(t_stack **stack_a,
				t_stack **stack_b, t_list **lst, int size);
void		algo_size_three(t_stack **stack_a, t_list **lst);
void		algo_size_four(t_stack **stack_a, t_stack **stack_b, t_list **lst);
void		algo_size_five(t_stack **stack_a, t_stack **stack_b, t_list **lst);

/* Optimisation and print functions                                           */

void		optimisation_print(t_list *lst);
void		swap_optimisation_print(t_list **lst);
void		rotate_optimisation_print(t_list **lst);
void		reverse_rotate_optimisation_print(t_list **lst);
void		push_print(t_list *lst);

#endif
