/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_little_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:46:19 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 12:35:31 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Redirect main to according size of stack_a if it <= 5                      */

void	algo_little_sort(t_stack **stack_a,
		t_stack **stack_b, t_list **lst, int size)
{
	if (size == 2)
	{
		swap_a(*stack_a, lst);
		return ;
	}
	if (size == 3)
		algo_size_three(stack_a, lst);
	if (size == 4)
		algo_size_four(stack_a, stack_b, lst);
	if (size == 5)
		algo_size_five(stack_a, stack_b, lst);
}

int	find_min_in_stack(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack != NULL)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

void	algo_size_three(t_stack **stack_a, t_list **lst)
{
	if ((*stack_a)->nb == 2)
		rotate_a(*stack_a, lst);
	if ((*stack_a)->next->nb == 2)
		reverse_rotate_a(*stack_a, lst);
	if ((*stack_a)->nb == 1)
		swap_a(*stack_a, lst);
}

void	algo_size_four(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	int	way;

	way = find_shortest_to_max(stack_a, 3);
	while (way != 0)
	{
		if (way > 0)
		{
			rotate_a(*stack_a, lst);
			way--;
		}
		else if (way < 0)
		{
			reverse_rotate_a(*stack_a, lst);
			way++;
		}
	}
	push_b(stack_a, stack_b, lst);
	algo_size_three(stack_a, lst);
	push_a(stack_b, stack_a, lst);
	rotate_a(*stack_a, lst);
}

void	algo_size_five(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	int	way;

	way = find_shortest_to_max(stack_a, 4);
	while (way != 0)
	{
		if (way > 0)
		{
			rotate_a(*stack_a, lst);
			way--;
		}
		else if (way < 0)
		{
			reverse_rotate_a(*stack_a, lst);
			way++;
		}
	}
	push_b(stack_a, stack_b, lst);
	algo_size_four(stack_a, stack_b, lst);
	push_a(stack_b, stack_a, lst);
	rotate_a(*stack_a, lst);
}
