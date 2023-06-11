/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 20:43:01 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/09 19:49:47 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_rotation(t_node **stack, t_node *cheap, char *rx, char *rrx)
{
	while (*stack != cheap)
	{
		if (cheap->bottom)
			move(stack, stack, rrx);
		else
			move(stack, stack, rx);
	}
}

static t_node	*return_cheapest(t_node *stack)
{
	t_node	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->price < cheapest->price)
			cheapest = stack;
		stack = stack->next;
	}
	return (cheapest);
}

void	move_nodes(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->bottom == cheapest->target->bottom)
	{
		if (cheapest->bottom)
			while (*a != cheapest->target && *b != cheapest)
				move(a, b, RRR);
		else
			while (*a != cheapest->target && *b != cheapest)
				move(a, b, RR);
	}
	finish_rotation(b, cheapest, RB, RRB);
	finish_rotation(a, cheapest->target, RA, RRA);
	move(a, b, PA);
}
