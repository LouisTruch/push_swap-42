/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pivots_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:06:25 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/05 21:07:12 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_by_pivot(t_stack **stack_a, t_stack **stack_b, t_list **lst, int max_pivot)
{
	int	i;
	int	way;

	i = 0;
	while (check_list_max_pivot(stack_a, max_pivot) == 1)
	{
		way = find_closest_to_push(stack_a, max_pivot);
		push_closest_to_b(stack_a, stack_b, lst, way);
	}
}

int	find_closest_to_push(t_stack **stack_a, int max_pivot)
{
	int		i;
	int		j;
	t_stack	*head;
	t_stack	*last;

	i = 0;
	j = -1;
	head = *stack_a;
	last = ft_stacklast(head);
	while (head != NULL || last != NULL)
	{
		if (head->nb <= max_pivot)
		{
			return (i);
		}
		if (last->nb <= max_pivot)
		{
			return (j);
		}
		i++;
		j--;
		head = head->next;
		last = last->prev;
	}
	return (0);
}

void	push_closest_to_b(t_stack **stack_a, t_stack **stack_b, t_list **lst, int way)
{
	if (way > 0)
	{
		while (way != 0)
		{
			rotate_a(*stack_a, lst);
			way--;
		}
	}
	else if (way < 0)
	{
		while (way != 0)
		{
			reverse_rotate_a(*stack_a, lst);
			way++;
		}
	}
	push_b(stack_a, stack_b, lst);
}

int	check_list_max_pivot(t_stack **stack_a, int max_pivot)
{
	t_stack	*head;

	head = *stack_a;
	while (head != NULL)
	{
		if (head->nb <= max_pivot)
			return (1);
		head = head->next;
	}
	return (0);
}
