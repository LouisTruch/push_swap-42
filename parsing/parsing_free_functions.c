/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:49:17 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/03 15:03:14 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_error_exit(void)
{
	ft_printf(RED"Error\n"NC);
	exit(0);
}

void	ft_free_array_str(char **array_str)
{
	int	i;

	i = 0;
	while (array_str[i])
	{
		free(array_str[i]);
		i++;
	}
	free(array_str[i]);
	free(array_str);
}
