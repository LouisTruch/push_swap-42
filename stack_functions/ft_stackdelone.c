/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:07:24 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/03 19:09:25 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackdelone(t_stack *stack)
{
	if (!stack)
		return ;
	stack->prev->next = stack->next;
	stack->next->prev = stack->prev;
	free (stack);
}
