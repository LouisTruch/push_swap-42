/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:30:25 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 20:35:09 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_a(t_stack *stack_a)
{
	int		tmp;

	if (!stack_a || stack_a->next == NULL)
		return ;
	tmp = stack_a->next->nb;
	stack_a->next->nb = stack_a->nb;
	stack_a->nb = tmp;
}
