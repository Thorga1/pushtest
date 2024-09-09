/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 19:19:31 by tordner           #+#    #+#             */
/*   Updated: 2024/07/25 19:59:43 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = len_stack(*stack);
	if (NULL == stack || NULL == (*stack) || 1 == len)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool check)
{
	rotate(a);
	if (!check)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool check)
{
	rotate(b);
	if (!check)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool check)
{
	rotate(a);
	rotate(b);
	if (!check)
		write(1, "rr\n", 3);
}
