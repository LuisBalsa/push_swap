/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:39:49 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/10 11:10:03 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tree(t_node **stack)
{
	t_node	*highest_node;
	t_node	*temp;
	int		highest;

	highest = INT_MIN;
	temp = *stack;
	while (temp)
	{
		if (temp->value > highest)
		{
			highest = temp->value;
			highest_node = temp;
		}
		temp = temp->next;
	}
	if (*stack == highest_node)
		move(stack, stack, RA);
	else if ((*stack)->next == highest_node)
		move(stack, stack, RRA);
	if ((*stack)->value > (*stack)->next->value)
		move(stack, stack, SA);
}

void	sort_five(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), RA, RRA);
		move(a, b, PB);
	}
}

void	sort(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		len_a;

	len_a = stack_size(*a);
	if (len_a == 5)
		sort_five(a, b);
	else
	{
		while (len_a-- > 3)
			move(a, b, PB);
	}
	sort_tree(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->bottom)
		while (*a != smallest)
			move(a, a, RRA);
	else
		while (*a != smallest)
			move(a, a, RA);
}
