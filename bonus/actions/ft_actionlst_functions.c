/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actionlst_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:36:36 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/08 11:37:07 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_action	*ft_actionnew(char *move)
{
	t_action	*new;

	new = malloc(sizeof(t_action));
	if (!new)
		return (NULL);
	new->move = move;
	new->next = NULL;
	return (new);
}

t_action	*ft_actionlast(t_action *action)
{
	t_action	*last;

	if (action == NULL)
		return (NULL);
	while (action != NULL)
	{
		last = action;
		action = action->next;
	}
	return (last);
}

void	ft_actionadd_back(t_action **action, t_action *new)
{
	t_action	*last;

	if (!action || !new)
		return ;
	if (*action == NULL)
		*action = new;
	else
	{
		last = ft_actionlast(*action);
		last->next = new;
	}
}

void	ft_actionclear(t_action **action)
{
	t_action	*tmp;
	t_action	*current;

	if (!*action)
		return ;
	current = *action;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->move);
		free(tmp);
	}
	*action = NULL;
}
