/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:49:53 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 12:23:03 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Take cleaned argv and create a linked list with these values              *
 * Then normalise in another linked list and free old one                    */

t_stack	*create_linked_list(char **array_str)
{
	unsigned int	i;
	t_stack			*head;
	t_stack			*new;
	t_stack			*normalized_stack;

	i = 0;
	head = NULL;
	while (array_str[i])
	{
		new = ft_stacknew(ft_atoi(array_str[i]));
		ft_stackadd_back(&head, new);
		i++;
	}
	normalized_stack = normalize_stack_nb(head);
	ft_stackclear(&head);
	ft_free_array_str(array_str);
	return (normalized_stack);
}

/* Take firstly created list, create an array with the same size and order   *
 * Bubble sort this array, then make a new linked list by browsing through   *
 * And comparing it with bubble_sorted arrayi                                */

t_stack	*normalize_stack_nb(t_stack *stack)
{
	int				i;
	unsigned int	size;
	int				*int_stack;
	t_stack			*head;
	t_stack			*normalized_stack;

	i = 0;
	size = ft_stacksize(stack);
	int_stack = malloc(sizeof(int) * size);
	if (!int_stack)
		return (NULL);
	head = stack;
	while (stack != NULL)
	{
		int_stack[i] = stack->nb;
		stack = stack->next;
		i++;
	}
	stack = head;
	bubble_sort(int_stack, size);
	normalized_stack = make_normalized_stack(stack, int_stack);
	free(int_stack);
	return (normalized_stack);
}

t_stack	*make_normalized_stack(t_stack *stack, int *int_stack)
{
	unsigned int	i;
	t_stack			*new_head;
	t_stack			*new_stack;

	new_head = NULL;
	while (stack != NULL)
	{
		i = 0;
		while (int_stack[i] != stack->nb)
			i++;
		new_stack = ft_stacknew(i);
		ft_stackadd_back(&new_head, new_stack);
		stack = stack->next;
	}
	return (new_head);
}

void	bubble_sort(int	*int_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (int_stack[j] > int_stack[j + 1])
			{
				tmp = int_stack[j];
				int_stack[j] = int_stack[j + 1];
				int_stack[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
