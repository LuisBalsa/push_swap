/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:24:18 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 23:48:42 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(t_node **a)
{
	free_stack(a);
	exit(1);
}

void	append_node(t_node **head, int value)
{
	t_node	*new;
	t_node	*last;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error(head);
	new->value = value;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return ;
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		++size;
	}
	return (size);
}

t_node	*find_smallest(t_node *stack)
{
	t_node	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}
