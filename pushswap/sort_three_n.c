/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:12:18 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 21:25:35 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	second_bigger(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->count;
	second = (*a)->next->count;
	third = (*a)->next->next->count;
	if (first < third)
	{
		rra(a, 0);
		sa(a, 0);
	}
	else
		rra(a, 0);
}

void	sort_three_n(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->count;
	second = (*a)->next->count;
	third = (*a)->next->next->count;
	if (first > second && first > third && second < third)
		ra(a, 0);
	else if (first > second && first > third)
	{
		rra(a, 0);
		rra(a, 0);
		sa(a, 0);
	}
	else if (first > second && second < third)
		sa(a, 0);
	else if (second > first && second > third)
		second_bigger(a);
	else if (third > first && third > second)
	{
		sa(a, 0);
		ra(a, 0);
	}
}
