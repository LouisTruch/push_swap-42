/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:30:25 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/04 14:47:03 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stack)
{
	int		tmp;

	if (!stack || (stack)->next == NULL)
		return ;
	tmp = stack->next->nb;
	stack->next->nb = stack->nb;
	stack->nb = tmp;
}
