/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:54:52 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/06 15:01:18 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	main_algorithm(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	int	i;
	int	pivot;
	int	max_pivot;
	int	size;

	i = 1;
	size = ft_stacksize(*stack_a);
	pivot = 3 + (size / 150);
	while (i <= pivot)
	{
		max_pivot = i * size / pivot;
		if (max_pivot == size - 1)
			push_by_pivot(stack_a, stack_b, lst, max_pivot);
		else
		{
			push_by_pivot(stack_a, stack_b, lst, max_pivot - 3);
			if ((*stack_a)->nb > (*stack_a)->next->nb)
				swap_a(*stack_a, lst);
		}
		i++;
	}
	while (*stack_b != NULL)
	{
		push_max_to_a(stack_a, stack_b, lst);
	}
}
