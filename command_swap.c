/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:37:24 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 00:41:19 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_node	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node	**b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node	**a, t_node	**b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
