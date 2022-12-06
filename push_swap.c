/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:01:09 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/06 15:01:26 by ltruchel         ###   ########.fr       */
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

/* Delete before pushing */

void	print_both_stack(t_stack *stack_a, t_stack *stack_b)
{
	char	c;

	c = 'x';
	while (stack_a != NULL || stack_b != NULL)
	{
		if (!stack_a || !stack_b)
		{
			if (!stack_a)
				ft_printf("%c     %i\n", c, stack_b->nb);
			else
				ft_printf("%i     %c\n", stack_a->nb, c);
		}
		else
			ft_printf("%i     %i\n", stack_a->nb, stack_b->nb);
		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
	ft_printf("A     B\n");
	ft_printf("*******\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*lst;

	if (ac <= 2)
		return (1);
	stack_a = parse_arguments(av);
	stack_b = NULL;
	lst = NULL;
//	print_both_stack(stack_a, stack_b);
	main_algorithm(&stack_a, &stack_b, &lst);
//	print_both_stack(stack_a, stack_b);
	optimisation_print(lst);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	ft_lstclear(&lst);
	return (0);
}
