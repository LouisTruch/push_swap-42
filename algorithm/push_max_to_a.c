/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_max_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:56:43 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 15:45:06 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_max_to_a(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	int			max;
	int			max_minus_one;
	int			way;
	int			way_minus_one;

	max = find_max_in_stack(stack_b);
	way = find_shortest_to_max(stack_b, max);
	max_minus_one = max - 1;
	way_minus_one = find_shortest_to_max(stack_b, max_minus_one);
	if (ft_abs(way) <= ft_abs(way_minus_one + 1))
	{
		put_max_on_top(stack_b, lst, way);
		push_a(stack_b, stack_a, lst);
	}
	else
	{
		put_max_on_top(stack_b, lst, way_minus_one);
		push_a(stack_b, stack_a, lst);
		max = find_max_in_stack(stack_b);
		way = find_shortest_to_max(stack_b, max);
		put_max_on_top(stack_b, lst, way);
		push_a(stack_b, stack_a, lst);
		swap_a(*stack_a, lst);
	}
}

int	find_shortest_to_max(t_stack **stack_b, int max)
{
	int		i;
	int		j;
	t_stack	*head;
	t_stack	*last;

	i = 0;
	j = -1;
	head = *stack_b;
	last = ft_stacklast(head);
	while (head != NULL || last != NULL)
	{
		if (head->nb == max)
			return (i);
		if (last->nb == max)
			return (j);
		i++;
		j--;
		head = head->next;
		last = last->prev;
	}
	return (0);
}

void	put_max_on_top(t_stack **stack_b, t_list **lst, int way)
{
	if (way > 0)
	{
		while (way != 0)
		{
			rotate_b(*stack_b, lst);
			way--;
		}
	}
	else if (way < 0)
	{
		while (way != 0)
		{
			reverse_rotate_b(*stack_b, lst);
			way++;
		}
	}
	return ;
}

int	find_max_in_stack(t_stack **stack_b)
{
	int		max;
	t_stack	*head;

	max = INT_MIN;
	head = *stack_b;
	while (head != NULL)
	{
		if (head->nb > max)
			max = head->nb;
		head = head->next;
	}
	return (max);
}
