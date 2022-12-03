/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:05:44 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/03 17:06:39 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new || !stack)
		return ;
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}
