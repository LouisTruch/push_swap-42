/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:05:11 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/03 15:50:53 by ltruchel         ###   ########.fr       */
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
			if (!str[i + 1]
				|| str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == ' ')
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
		if (ft_strlen(array_str[i]) > 11)
			return (0);
		if (ft_atoi_overflow(array_str[i]) == 2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(char **array_str)
{
	int	i;
	int	j;

	i = 0;
	while (array_str[i])
	{
		j = 0;
		while (array_str[j])
		{
			if (i == j)
			{
				j++;
				if (!array_str[j])
					break ;
			}
			if (ft_strcmp(array_str[i], array_str[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
