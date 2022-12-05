/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:14 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/05 13:01:08 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_b(t_stack *stack_b, t_list **lst)
{
	int		tmp;
	t_list	*new;

	if (!stack_b || stack_b->next == NULL)
		return ;
	tmp = stack_b->next->nb;
	stack_b->next->nb = stack_b->nb;
	stack_b->nb = tmp;
	new = ft_lstnew(2);
	ft_lstadd_back(lst, new);
}
