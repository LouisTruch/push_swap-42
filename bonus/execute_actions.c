/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:00:43 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 23:03:24 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_actions_second(t_stack **stack_a,
		t_stack **stack_b, t_action *action)
{
	if (ft_strcmp(action->move, "rb\n") == 0)
		rotate_b(*stack_b);
	if (ft_strcmp(action->move, "rr\n") == 0)
		rr(*stack_a, *stack_b);
	if (ft_strcmp(action->move, "rra\n") == 0)
		reverse_rotate_a(*stack_a);
	if (ft_strcmp(action->move, "rrb\n") == 0)
		reverse_rotate_b(*stack_b);
	if (ft_strcmp(action->move, "rrr\n") == 0)
		rrr(*stack_a, *stack_b);
}

void	execute_actions(t_stack **stack_a, t_stack **stack_b, t_action *action)
{
	while (action)
	{
		if (ft_strcmp(action->move, "sa\n") == 0)
			swap_a(*stack_a);
		if (ft_strcmp(action->move, "sb\n") == 0)
			swap_b(*stack_b);
		if (ft_strcmp(action->move, "ss\n") == 0)
			ss(*stack_a, *stack_b);
		if (ft_strcmp(action->move, "pa\n") == 0)
			push_a(stack_b, stack_a);
		if (ft_strcmp(action->move, "pb\n") == 0)
			push_b(stack_a, stack_b);
		if (ft_strcmp(action->move, "ra\n") == 0)
			rotate_a(*stack_a);
		execute_actions_second(stack_a, stack_b, action);
		action = action->next;
	}
}
