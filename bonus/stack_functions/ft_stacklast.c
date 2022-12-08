/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:50:40 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 20:43:50 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	if (stack == NULL)
		return (NULL);
	while (stack != NULL)
	{
		last = stack;
		stack = stack->next;
	}
	return (last);
}
