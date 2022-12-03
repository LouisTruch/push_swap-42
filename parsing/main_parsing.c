/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:08:18 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/03 21:14:42 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*parse_arguments(char **av)
{
	char	*argv_list;
	char	**array_str;
	t_stack	*stack;

	argv_list = join_argv(av);
	if (check_characters(argv_list) == 0)
	{
		free(argv_list);
		ft_print_error_exit();
	}
	array_str = ft_split(argv_list, ' ');
	free(argv_list);
	if (check_overflow(array_str) == 0 || check_duplicates(array_str) == 0)
	{
		ft_free_array_str(array_str);
		ft_print_error_exit();
	}
	stack = create_linked_list(array_str);
	return (stack);
}

char	*join_argv(char **av)
{
	char	*argv_list;
	char	*tmp;
	int		i;

	i = 1;
	argv_list = ft_calloc(1, 1);
	while (av[i])
	{
		tmp = ft_strdup(argv_list);
		free(argv_list);
		argv_list = ft_strjoin_add_space(tmp, av[i]);
		free(tmp);
		i++;
	}
	return (argv_list);
}
