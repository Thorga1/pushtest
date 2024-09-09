/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:19:25 by tordner           #+#    #+#             */
/*   Updated: 2024/07/25 19:59:16 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = len_stack(*stack);
	if (NULL == stack || NULL == (*stack) || 1 == len)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack) = last_node;
	(*stack)->next->prev = (*stack);
}

void	rra(t_stack_node **a, bool check)
{
	rev_rotate(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool check)
{
	rev_rotate(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!check)
		write(1, "rrr\n", 4);
}
