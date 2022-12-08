/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:39:16 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 20:34:43 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_stack	*head;
	t_stack	*last;
	int		last_tmp;

	if (!stack)
		return ;
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
