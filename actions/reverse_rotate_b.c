/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:02:24 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/04 16:02:42 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_b(t_stack *stack)
{
	t_stack	*head;
	t_stack	*last;
	int		last_tmp;

	head = stack;
	last = ft_stacklast(stack);
	last_tmp = last->nb;
	while (last != NULL)
	{
		if (last == head)
		{
			last->nb = last_tmp;
			break ;
		}
		last->nb = last->prev->nb;
		last = last->prev;
	}
}
