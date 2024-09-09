/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:31:56 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 18:59:03 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_node	*find_last(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	len_stack(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (NULL == stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	create_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = n;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	assign_count(t_stack_node *a)
{
	int				i;
	t_stack_node	*x;
	t_stack_node	*y;

	x = a;
	while (x != NULL)
	{
		i = 0;
		y = a;
		while (y != NULL)
		{
			if (x->value > y->value)
				i++;
			y = y->next;
		}
		printf("count: %d\n", i);
		x->count = i;
		x = x->next;
	}
}
