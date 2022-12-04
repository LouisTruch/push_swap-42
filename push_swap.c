/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:01:09 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/04 16:04:55 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

/* Delete before pushing */

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%i\n", stack->nb);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 2)
		return (1);
	stack_a = parse_arguments(av);
	stack_b = NULL;
	print_stack(stack_a);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	ft_printf("A--\n");
	print_stack(stack_a);
	ft_printf("B--\n");
	print_stack(stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	return (0);
}
