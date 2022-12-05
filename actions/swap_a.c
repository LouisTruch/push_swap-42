/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 21:30:25 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/05 12:59:14 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *stack_a, t_list **lst)
{
	int		tmp;
	t_list	*new;

	if (!stack_a || stack_a->next == NULL)
		return ;
	tmp = stack_a->next->nb;
	stack_a->next->nb = stack_a->nb;
	stack_a->nb = tmp;
	new = ft_lstnew(1);
	ft_lstadd_back(lst, new);
}
