/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:37:04 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 18:58:28 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_tab(char **new)
{
	int	i;

	i = 0;
	if (NULL == new || NULL == *new)
		return ;
	while (new[i])
		free(new[i++]);
	free(new - 1);
}

void	init_stack(t_stack_node **a, char **av, bool check_tab)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (err_syntax(av[i]))
			err_free(a, av, check_tab);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			err_free(a, av, check_tab);
		if (err_repetition(*a, (int)n))
			err_free(a, av, check_tab);
		create_node(a, (int)n);
		i++;
	}
	if (check_tab)
		free_tab(av);
}
