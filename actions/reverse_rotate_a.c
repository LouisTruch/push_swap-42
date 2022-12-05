/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:39:16 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/05 16:58:24 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate_a(t_stack *stack, t_list **lst)
{
	t_stack	*head;
	t_stack	*last;
	t_list	*new;
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
	new = ft_lstnew(5);
	ft_lstadd_back(lst, new);
}
