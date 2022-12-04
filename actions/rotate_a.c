/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:06:31 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/04 14:36:16 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_stack	*head;
	t_stack	*last;
	int		head_tmp;

	head = stack;
	head_tmp = head->nb;
	last = ft_stacklast(stack);
	while (stack != NULL)
	{
		if (stack == last)
		{
			stack->nb = head_tmp;
			break ;
		}
		stack->nb = stack->next->nb;
		stack = stack->next;
	}
}