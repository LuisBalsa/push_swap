/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:39:49 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/12 11:44:54 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	get_final_index(t_node *a, int size)
{
	t_node	*temp;
	t_node	*max_address;
	int		max_n;

	while (size--)
	{
		temp = a;
		max_n = INT_MIN;
		max_address = NULL;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->final_index == 0)
				temp->final_index = 1;
			else if (temp->value > max_n && temp->final_index == 0)
			{
				max_n = temp->value;
				max_address = temp;
				temp = a;
			}
			else
				temp = temp->next;
		}
		if (max_address)
			max_address->final_index = size + 1;
	}
}

static void	push_b_save_3(t_node **a, t_node **b, int size)
{
	int		pushed;
	int		i;

	pushed = 0;
	i = 0;
	get_final_index(*a, size);
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->final_index <= size / 2)
		{
			move(a, b, PB);
			pushed++;
		}
		else
			move(a, NULL, RA);
		i++;
	}
	while (size - pushed > 3)
	{
		move(a, b, PB);
		pushed++;
	}
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
		push_b_save_3(a, b, len_a);
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
