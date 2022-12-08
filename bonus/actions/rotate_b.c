/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:36:47 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 20:34:53 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate_b(t_stack *stack)
{
	t_stack	*head;
	t_stack	*last;
	int		head_tmp;

	if (!stack)
		return ;
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
