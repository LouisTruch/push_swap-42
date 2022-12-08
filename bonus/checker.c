/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:32:22 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 11:56:24 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stacks_and_actions(t_stack **stack_a,
			t_stack **stack_b, t_action **action)
{
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	ft_actionclear(action);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_action	*action;

	if (ac <= 1)
		return (1);
	stack_a = parse_arguments(av);
	if (!stack_a->next)
	{
		free (stack_a);
		return (1);
	}
	check_duplicates(&stack_a);
	action = get_actions(&stack_a);
	stack_b = NULL;
	execute_actions(&stack_a, &stack_b, action);
	if (check_stacks(stack_a, stack_b) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stacks_and_actions(&stack_a, &stack_b, &action);
	return (0);
}
