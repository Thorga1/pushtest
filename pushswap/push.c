/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:42:47 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 21:44:47 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node;

	if (NULL == *src)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if (!check)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool check)
{
	push(b, a);
	if (!check)
		write(1, "pb\n", 3);
}
