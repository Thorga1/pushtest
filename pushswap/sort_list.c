/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:17:57 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 21:23:57 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two_n(t_stack_node **a)
{
	if ((*a)->count > (*a)->next->count)
		sa(a, 0);
}

int	is_sorted(t_stack_node *a)
{
	t_stack_node	*head;

	head = a;
	while (head->next != NULL)
	{
		if (head->count > head->next->count)
			return (1);
		head = head->next;
	}
	return (0);
}

void	sort_it(t_stack_node **a, t_stack_node **b, int args)
{
	if (2 == args)
		sort_two_n(a);
	if (3 == args)
		sort_three_n(a);
	if (5 == args)
		sort_five_n(a, b);
}
