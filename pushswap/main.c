/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:55:25 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 22:28:50 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_args(char **av)
{
	int	i;

	i = 1;
	while (av[i + 1] != NULL)
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				bit_compare;
	int				args;

	a = NULL;
	b = NULL;
	bit_compare = 1;
	if (1 == ac || (2 == ac && !av[1][0]))
		return (1);
	else if (2 == ac)
		av = mimic_av(ft_split(av[1], ' '));
	init_stack(&a, av + 1, 2 == ac);
	assign_count(a);
	args = count_args(av);
	while (is_sorted(a) == 1)
		sort_it(&a, &b, args);
	free_stack(&a);
	return (0);
}
