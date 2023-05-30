/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:39:49 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/30 12:10:28 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_sorted(t_node *stack)
{
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}

/* void    sort_tree(t_node **stack)
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
		ra(stack, false);
	else if ((*stack)->next == highest_node)
		rra(stack, false);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, false);
}
 */