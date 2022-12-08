/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:06:28 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 12:40:01 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_print_error_exit(char *move, char **rules,
		t_action *action, t_stack **stack_a)
{
	free(move);
	free(rules);
	ft_actionclear(&action);
	ft_stackclear(stack_a);
	write(2, "Error\n", 6);
	exit (0);
}

char	**define_rules(void)
{
	char	**rules;

	rules = malloc(sizeof(char *) * 11);
	rules[0] = "sa\n";
	rules[1] = "sb\n";
	rules[2] = "ss\n";
	rules[3] = "pa\n";
	rules[4] = "pb\n";
	rules[5] = "ra\n";
	rules[6] = "rb\n";
	rules[7] = "rr\n";
	rules[8] = "rra\n";
	rules[9] = "rrb\n";
	rules[10] = "rrr\n";
	return (rules);
}

/* Check if input given is a valid action,                                  *
 * Then add it to the action's linked list                                  */

void	parse_input(t_action **action, char *move, t_stack **stack_a)
{
	int			i;
	int			count;
	char		**rules;
	t_action	*new;

	rules = define_rules();
	i = 0;
	count = 0;
	while (i < 11)
	{
		if (ft_strcmp(rules[i], move) != 0)
			count++;
		i++;
	}
	if (count != 10)
		free_print_error_exit(move, rules, *action, stack_a);
	new = ft_actionnew(ft_strdup(move));
	ft_actionadd_back(action, new);
	free (rules);
}

t_action	*get_actions(t_stack **stack_a)
{
	char		*move;
	t_action	*action;

	action = NULL;
	move = get_next_line(0);
	while (move)
	{
		parse_input(&action, move, stack_a);
		free (move);
		move = get_next_line(0);
	}
	return (action);
}
