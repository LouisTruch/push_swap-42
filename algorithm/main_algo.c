/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:54:52 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 12:32:53 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Push chunks in B, number of chunk is determined by size of stack_a/150+5  *
 * Find closest number to inferior to first chunk max_pivot then push it     *
 * Check if said number is above or beyond median of this max_pivot,         *
 * If it above, put it to the bottom of stack_b by doing an RB               *
 * For last chunk, doesn't push max and max-1, just sort them by doing SA    *
 * If needed                                                                 *
 * When A is empty, find closest to push between B' max and max-1,           *
 * Then push it and swap A if max-1 was pushed first                         *
 * Repeat until B is empty, A should then be sorted by ascending order       */

void	main_algorithm(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	int	i;
	int	pivot;
	int	size;
	int	max_pivot;

	i = 1;
	size = ft_stacksize(*stack_a);
	pivot = 5 + (size / 150);
	while (i <= pivot)
	{
		max_pivot = i * size / pivot;
		if (i < pivot)
			push_by_pivot(stack_a, stack_b, lst, max_pivot);
		else
		{
			push_by_pivot(stack_a, stack_b, lst, max_pivot - 3);
			if ((*stack_a)->next && (*stack_a)->nb > (*stack_a)->next->nb)
				swap_a(*stack_a, lst);
		}
		i++;
	}
	while (*stack_b != NULL)
		push_max_to_a(stack_a, stack_b, lst);
}
