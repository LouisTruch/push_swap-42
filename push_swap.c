/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:01:09 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/03 21:16:24 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (1);
	stack = parse_arguments(av);
	ft_stackclear(&stack);
	return (0);
}
