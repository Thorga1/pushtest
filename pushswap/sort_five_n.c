/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:16:19 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 22:29:43 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_smallest_position(t_stack_node *a, int smallest)
{
	int				pos;
	t_stack_node	*temp;

	temp = a;
	pos = 0;
	while (temp != NULL)
	{
		if (smallest == temp->count)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (-1);
}

int	find_smallest_count(t_stack_node *head)
{
	int				smallest;
	t_stack_node	*temp;

	if (head == NULL)
		return (-1);
	smallest = head->count;
	temp = head;
	while (temp != NULL)
	{
		if (temp->count < smallest)
			smallest = temp->count;
		temp = temp->next;
	}
	return (smallest);
}

void	sort_five_n(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;
	int				smallest;
	int				pos;

	while (*a != NULL)
	{
		temp = *a;
		smallest = find_smallest_count(*a);
		while ((*a)->count != smallest)
		{
			pos = find_smallest_position(*a, smallest);
			if (pos <= 5 / 2)
				ra(a, 0);
			else
				rra(a, 0);
		}
		pb(b, a, 0);
	}
	while (*b != NULL)
		pa(a, b, 0);
}
