/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:49:40 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/05 16:53:03 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack **stack_b, t_stack **stack_a, t_list **lst)
{
	t_stack	*head_b;
	t_stack	*new_head_a;
	t_list	*new;

	if (!*stack_b)
		return ;
	new_head_a = ft_stacknew((*stack_b)->nb);
	ft_stackadd_front(stack_a, new_head_a);
	head_b = *stack_b;
	if ((*stack_b)->next != NULL)
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	else
		*stack_b = NULL;
	free (head_b);
	new = ft_lstnew(7);
	ft_lstadd_back(lst, new);
}
