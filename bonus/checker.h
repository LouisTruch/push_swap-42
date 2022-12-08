/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:36:15 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 11:50:01 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int					nb;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

typedef struct s_action
{
	char			*move;
	struct s_action	*next;
}	t_action;

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

void		swap_a(t_stack *stack_a);
void		swap_b(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		rotate_a(t_stack *stack);
void		rotate_b(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate_a(t_stack *stack);
void		reverse_rotate_b(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		push_a(t_stack **stack_b, t_stack **stack_a);
void		push_b(t_stack **stack_a, t_stack **stack_b);

/* Actions' linked list functions*/

t_action	*ft_actionnew(char *move);
void		ft_actionadd_back(t_action **action, t_action *new);
void		ft_actionclear(t_action **action);
t_action	*get_actions(t_stack **stack_a);
void		ft_actionclear(t_action **action);
void		execute_actions(t_stack **stack_a,
				t_stack **stack_b, t_action *action);
int			check_stacks(t_stack *stack_a, t_stack *stack_b);

/* Utils                                                                      */

int			ft_strcmp(const char *s1, const char *s2);

#endif
