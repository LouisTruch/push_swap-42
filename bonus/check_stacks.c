/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:09:27 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 12:38:49 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max;

	i = 0;
	max = ft_stacksize(stack_a) - 1;
	if (stack_b)
		return (0);
	while (i <= max)
	{
		if (stack_a->nb != i)
			return (0);
		i++;
		stack_a = stack_a->next;
	}
	return (1);
}
