/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:14 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 20:38:05 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_b(t_stack *stack_b)
{
	int		tmp;

	if (!stack_b || stack_b->next == NULL)
		return ;
	tmp = stack_b->next->nb;
	stack_b->next->nb = stack_b->nb;
	stack_b->nb = tmp;
}
