/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_numbers_from_zero.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:14 by naherbal          #+#    #+#             */
/*   Updated: 2024/07/26 15:32:31 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_numbers_from_zero(t_data *data)
{
	int		i;
	t_node	*x;
	t_node	*y;

	x = data->a;
	while (x != NULL)
	{
		i = 0;
		y = data->a;
		while (y != NULL)
		{
			if (x->nb > y->nb)
				i++;
			y = y->next;
		}
		x->s_nb = i;
		x = x->next;
	}
}
