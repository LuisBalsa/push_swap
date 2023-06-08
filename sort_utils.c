/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:22:55 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 20:35:26 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (!stack)
		return ;
	centerline = stack_size(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= centerline)
			stack->bottom = false;
		else
			stack->bottom = true;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	set_price(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->price = b->position;
		b->target->price = b->target->position;
		if (b->bottom)
			b->price = len_b - b->position;
		if (b->target->bottom)
			b->target->price = len_a - b->target->position;
		if (b->bottom == b->target->bottom)
			b->price = max(b->price, b->target->price);
		else
			b->price += b->target->price;
		b = b->next;
	}
}

void	init_nodes(t_node *a, t_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
}
