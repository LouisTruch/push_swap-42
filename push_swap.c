/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:01:09 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 18:47:23 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_stacks_and_list(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	ft_lstclear(lst);
}

void	check_if_already_sorted(t_stack **stack_a)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = *stack_a;
	while (head != NULL)
	{
		if (head->nb != i)
			return ;
		i++;
		head = head->next;
	}
	ft_stackclear(stack_a);
	exit (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*lst;
	int		size;

	if (ac <= 1)
		return (1);
	stack_a = parse_arguments(av);
	if (!stack_a->next)
	{
		free (stack_a);
		return (1);
	}
	check_duplicates(&stack_a);
	check_if_already_sorted(&stack_a);
	size = ft_stacksize(stack_a);
	stack_b = NULL;
	lst = NULL;
	if (size <= 5)
		algo_little_sort(&stack_a, &stack_b, &lst, size);
	else
		main_algorithm(&stack_a, &stack_b, &lst);
	optimisation_print(lst);
	free_stacks_and_list(&stack_a, &stack_b, &lst);
	return (0);
}
