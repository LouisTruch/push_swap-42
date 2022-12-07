/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation_and_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:09:14 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/07 13:45:26 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	optimisation_print(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->move == 1 || lst->move == 2)
			swap_optimisation_print(&lst);
		if (lst->move == 3 || lst->move == 4)
			rotate_optimisation_print(&lst);
		if (lst->move == 5 || lst->move == 6)
			reverse_rotate_optimisation_print(&lst);
		if (lst->move == 7 || lst->move == 8)
			push_print(lst);
		lst = lst->next;
	}
}

void	swap_optimisation_print(t_list **lst)
{
	if ((*lst)->move == 1)
	{
		if ((*lst)->next && (*lst)->next->move == 2)
		{
			ft_printf("ss\n");
			*lst = (*lst)->next;
			return ;
		}
		ft_printf("sa\n");
	}
	else
	{
		if ((*lst)->next && (*lst)->next->move == 1)
		{
			ft_printf("ss\n");
			*lst = (*lst)->next;
			return ;
		}
		ft_printf("sb\n");
	}
}

void	rotate_optimisation_print(t_list **lst)
{
	if ((*lst)->move == 3)
	{
		if ((*lst)->next && (*lst)->next->move == 4)
		{
			ft_printf("rr\n");
			*lst = (*lst)->next;
			return ;
		}
		ft_printf("ra\n");
	}
	else
	{
		if ((*lst)->next && (*lst)->next->move == 3)
		{
			ft_printf("rr\n");
			*lst = (*lst)->next;
			return ;
		}
		ft_printf("rb\n");
	}
}

void	reverse_rotate_optimisation_print(t_list **lst)
{
	if ((*lst)->move == 5)
	{
		if ((*lst)->next && (*lst)->next->move == 6)
		{
			ft_printf("rrr\n");
			*lst = (*lst)->next;
			return ;
		}
		ft_printf("rra\n");
	}
	else
	{
		if ((*lst)->next && (*lst)->next->move == 5)
		{
			ft_printf("rrr\n");
			*lst = (*lst)->next;
			return ;
		}
		ft_printf("rrb\n");
	}
}

void	push_print(t_list *lst)
{
	if (lst->move == 7)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
