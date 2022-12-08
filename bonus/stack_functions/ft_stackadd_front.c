/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:05:44 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 20:43:35 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
