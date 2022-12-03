/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:55:17 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/03 21:13:55 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!tmp)
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}
