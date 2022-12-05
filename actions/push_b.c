/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:01:34 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/05 21:36:04 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_b(t_stack **stack_a, t_stack **stack_b, t_list **lst)
{
	t_stack	*head_a;
	t_stack	*new_head_b;
	t_list	*new;

	if (!*stack_a)
		return ;
	new_head_b = ft_stacknew((*stack_a)->nb);
	ft_stackadd_front(stack_b, new_head_b);
	head_a = *stack_a;
	if ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	else
		*stack_a = NULL;
	free (head_a);
	new = ft_lstnew(8);
	ft_lstadd_back(lst, new);
}
