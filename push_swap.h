/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:04:51 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 00:05:38 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct node
{
	int			value;
	int			position;
	int			final_index;
	int			price;
	bool		bottom;
	struct node	*target;
	struct node	*next;
}				t_node;

void			free_stack(t_node **a);
void			free_array(char **argv);
long			ft_atol(const char *str);
void			append_node(t_node **head, int value);
void			sort_tree(t_node **stack);
bool			is_sorted(t_node *stack);
int				stack_size(t_node *stack);
void			error_exit(t_node **a);
void			swap(t_node **stack);
void			sa(t_node **a);
void			sb(t_node **b);
void			ss(t_node **a, t_node **b);
void			push(t_node **src, t_node **dst);
void			pa(t_node **a, t_node **b);
void			pb(t_node **a, t_node **b);
void			rotate(t_node **stack);
void			ra(t_node **a);
void			rb(t_node **b);
void			rr(t_node **a, t_node **b);
void			reverse_rotate(t_node **stack);
void			rra(t_node **a);
void			rrb(t_node **b);
void			rrr(t_node **a, t_node **b);

#endif
