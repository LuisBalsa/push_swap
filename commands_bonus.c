/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:37:24 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/12 12:24:17 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_node **a, t_node **b, char *cmd)
{
	t_node	*tmp;

	if (!ft_strncmp(cmd, SA, ft_strlen(SA))
		|| !ft_strncmp(cmd, SS, ft_strlen(SS)))
	{
		if (!*a || !(*a)->next)
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (!ft_strncmp(cmd, SB, ft_strlen(SB))
		|| !ft_strncmp(cmd, SS, ft_strlen(SS)))
		swap(b, a, SA);
}

void	push_func(t_node **a, t_node **b, char *cmd)
{
	t_node	*tmp;

	if (!ft_strncmp(cmd, PA, ft_strlen(PA)))
	{
		if (!*b)
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (!ft_strncmp(cmd, PB, ft_strlen(PB)))
		push_func(b, a, PA);
}

void	rotate(t_node **a, t_node **b, char *cmd)
{
	t_node	*tmp;
	t_node	*last;

	if (!ft_strncmp(cmd, RA, ft_strlen(RA))
		|| !ft_strncmp(cmd, RR, ft_strlen(RR)))
	{
		if (!*a || !(*a)->next)
			return ;
		tmp = *a;
		*a = (*a)->next;
		last = *a;
		while (last->next)
			last = last->next;
		last->next = tmp;
		tmp->next = NULL;
	}
	if (!ft_strncmp(cmd, RB, ft_strlen(RB))
		|| !ft_strncmp(cmd, RR, ft_strlen(RR)))
		rotate(b, a, RA);
}

void	reverse_rotate(t_node **a, t_node **b, char *cmd)
{
	t_node	*temp;
	t_node	*last;

	if (!ft_strncmp(cmd, RRA, ft_strlen(RRA))
		|| !ft_strncmp(cmd, RRR, ft_strlen(RRR)))
	{
		if (!*a || !(*a)->next)
			return ;
		temp = *a;
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (!ft_strncmp(cmd, RRB, ft_strlen(RRB))
		|| !ft_strncmp(cmd, RRR, ft_strlen(RRR)))
		reverse_rotate(b, a, RRA);
}

void	move(t_node **first, t_node **second, char *cmd)
{
	if (!ft_strncmp(cmd, SA, ft_strlen(SA))
		|| !ft_strncmp(cmd, SB, ft_strlen(SB))
		|| !ft_strncmp(cmd, SS, ft_strlen(SS)))
		swap(first, second, cmd);
	else if (!ft_strncmp(cmd, PA, ft_strlen(PA))
		|| !ft_strncmp(cmd, PB, ft_strlen(PB)))
		push_func(first, second, cmd);
	else if (!ft_strncmp(cmd, RA, ft_strlen(RA))
		|| !ft_strncmp(cmd, RB, ft_strlen(RB))
		|| !ft_strncmp(cmd, RR, ft_strlen(RR)))
		rotate(first, second, cmd);
	else if (!ft_strncmp(cmd, RRA, ft_strlen(RRA))
		|| !ft_strncmp(cmd, RRB, ft_strlen(RRB))
		|| !ft_strncmp(cmd, RRR, ft_strlen(RRR)))
		reverse_rotate(first, second, cmd);
	ft_putstr_fd(cmd, 1);
}
