/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:04:24 by tordner           #+#    #+#             */
/*   Updated: 2024/07/29 18:46:35 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*node;

	if (NULL == stack)
		return ;
	node = *stack;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

int	err_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	err_repetition(t_stack_node *a, int n)
{
	if (NULL == a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	err_free(t_stack_node **a, char **av, bool check_tab)
{
	free_stack(a);
	if (check_tab)
		free_tab(av);
	write(2, "Error\n", 6);
	exit(1);
}
