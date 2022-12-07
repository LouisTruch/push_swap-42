/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:05:11 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 18:51:01 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_characters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			if (str[i] != ' ' && str[i] != '+' && str[i] != '-')
				return (0);
		if (str[i] == '+' || str[i] == '-')
		{
			if (!str[i + 1] || str[i + 1] == '+'
				|| str[i + 1] == '-' || str[i + 1] == ' ')
				return (0);
			if (str[i - 1] && (str[i - 1] >= '0' && str[i - 1] <= '9'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_overflow(char **array_str)
{
	int	i;

	i = 0;
	while (array_str[i])
	{
		if (ft_atoi_overflow(array_str[i]) == 2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_for_empty_array(char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (av[i])
	{
		len = ft_strlen(av[i]);
		if (len == 0)
			return (0);
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	check_duplicates(t_stack **stack_a)
{
	int		size;
	int		*dupli;
	t_stack	*head;

	head = *stack_a;
	size = ft_stacksize(head);
	dupli = ft_calloc(sizeof(int), size);
	while (head != NULL)
	{
		if (dupli[head->nb] == 1)
		{
			free (dupli);
			ft_stackclear(stack_a);
			ft_print_error_exit();
		}
		else
			dupli[head->nb] = 1;
		head = head->next;
	}
	free (dupli);
}
