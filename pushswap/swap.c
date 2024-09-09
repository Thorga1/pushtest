/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:49:42 by tordner           #+#    #+#             */
/*   Updated: 2024/07/26 13:56:52 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack_node **head)
{
	int	len;

	len = len_stack(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, bool check)
{
	swap(a);
	if (!check)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool check)
{
	swap(b);
	if (!check)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool check)
{
	swap(a);
	swap(b);
	if (!check)
		write(1, "ss\n", 3);
}
