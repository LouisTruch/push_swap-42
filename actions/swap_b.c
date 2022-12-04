/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:14 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/04 14:48:18 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_stack *stack)
{
	int		tmp;

	if (!stack || stack->next == NULL)
		return ;
	tmp = stack->next->nb;
	stack->next->nb = stack->nb;
	stack->nb = tmp;
}
