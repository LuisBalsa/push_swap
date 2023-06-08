/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:04:51 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 23:50:39 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

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

void	free_stack(t_node **a);
void	free_array(char **argv);
long	ft_atol(const char *str);
void	error_exit(void);
void	append_node(t_node **head, int value);
int		stack_size(t_node *stack);
void	sort(t_node **a, t_node **b);
void	sort_tree(t_node **stack);
void	sort_five(t_node **a, t_node **b);
bool	is_sorted(t_node *stack);
void	set_current_position(t_node *stack);
t_node	*find_smallest(t_node *stack);
void	init_nodes(t_node *a, t_node *b);
void	swap(t_node **a, t_node **b, char *cmd);
void	push_func(t_node **src, t_node **dst);
void	rotate(t_node **a, t_node **b, char *cmd);
void	reverse_rotate(t_node **a, t_node **b, char *cmd);
void	move(t_node **first, t_node **second, char *cmd);
void	move_nodes(t_node **a, t_node **b);
void	finish_rotation(t_node **stack, t_node *cheap, char *rx, char *rrx);

#endif
