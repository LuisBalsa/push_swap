/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:25:30 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/12 12:24:30 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	error_repetition(t_node *a, int nbr)
{
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	error_free(t_node **a, char **argv, bool argc_2)
{
	if (argc_2)
		free_array(argv);
	free_stack(a);
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	error_syntax(char *nbr)
{
	if (*nbr == '-' || *nbr == '+')
		++nbr;
	if (!ft_isdigit(*nbr))
		return (1);
	while (*nbr)
	{
		if (!ft_isdigit(*nbr))
			return (1);
		++nbr;
	}
	return (0);
}
