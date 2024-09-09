/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mimic_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <tordner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:38:22 by tordner           #+#    #+#             */
/*   Updated: 2024/07/26 19:06:00 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_new(char **new)
{
	int	i;

	i = 0;
	if (new == NULL)
		return ;
	while (new[i] != NULL)
	{
		free(new[i]);
		i++;
	}
	free(new);
}

char	**mimic_av(char **new)
{
	char	**av;
	int		i;
	int		count;
	int		j;

	j = 0;
	i = 0;
	count = 0;
	while (new[count])
		count++;
	av = (char **)malloc((sizeof(char *) * (count + 2)));
	if (NULL == av)
		return (0);
	av[i] = NULL;
	i++;
	while (j < count)
	{
		av[i] = ft_strdup(new[j]);
		i++;
		j++;
	}
	av[i] = NULL;
	free_new(new);
	return (av);
}
