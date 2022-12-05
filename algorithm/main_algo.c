/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:54:52 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/05 21:49:38 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	main_algorithm(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	int	i;
	int	pivot;
	int	size;
	int	max;

	i = 1;
	size = ft_stacksize(*stack_a);
	max = ft_stacksize(*stack_a) - 1;
	pivot = 3 + (size / 150);
	while (i <= pivot)
	{
		push_by_pivot(stack_a, stack_b, lst, size / pivot * i);
		i++;
	}
	while (*stack_b != NULL)
	{
		push_max_to_a(stack_a, stack_b, lst, &max);
	}
}

void	push_max_to_a(t_stack **stack_a, t_stack **stack_b, t_list **lst, int *max)
{
	static int	way;

	way = find_shortest_to_max(stack_b, max);
	put_max_on_top(stack_b, lst, &way);
	push_a(stack_b, stack_a, lst);
	*max -= 1;
}

int	find_shortest_to_max(t_stack **stack_b, int *max)
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
		if (head->nb == *max)
			return (i);
		if (last->nb == *max)
			return (j);
		i++;
		j--;
		head = head->next;
		last = last->prev;
	}
	return (0);
}

void	put_max_on_top(t_stack **stack_b, t_list **lst, int *way)
{
	if (*way > 0)
	{
		while (*way != 0)
		{
			rotate_b(*stack_b, lst);
			way--;
		}
	}
	else if (*way < 0)
	{
		while (*way != 0)
		{
			reverse_rotate_b(*stack_b, lst);
			way++;
		}
	}
	else
		return ;
}
