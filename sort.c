/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:39:49 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 17:51:56 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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

void	sorte_five(t_node **a, t_node **b)
{
	while (stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		push(a, b, &push_func, PB);
	}
}

void	sort(t_node **a, t_node **b)
{
	t_node	*smallest;
	int		len_a;

	len_a = stack_size(*a);
	if (len_a == 5)
		sorte_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
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
			move_one(a, &reverse_rotate, RRA);
	else
		while (*a != smallest)
			move_one(a, &rotate, RA);
}
