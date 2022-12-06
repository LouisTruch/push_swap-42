/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_little_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:46:19 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/06 16:26:27 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_little_sort(t_stack **stack_a, t_stack **stack_b, t_list **lst, int size)
{
	if (size == 2)
	{
		swap_a(*stack_a, lst);
		return ;
	}
	algo_size_three(stack_a, stack_b, lst);
}

void	algo_size_three(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	int	max;
	int	max_index;

	max_index = find_max_index(stack_a);
	while (max_index != 2)
	{
		reverse_rotate_a(*stack_a, lst);
		max_index += 1;
	}
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		swap_a(*stack_a, lst);
}

int	find_max_index(t_stack **stack_a)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = *stack_a;
	while (head != NULL)
	{
		if (head->nb == 2)
			return (i);
		i++;
		head = head->next;
	}
	return (0);
}
