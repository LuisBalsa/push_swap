/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:04:51 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 17:20:27 by luide-so         ###   ########.fr       */
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
void	append_node(t_node **head, int value);
void	sort_tree(t_node **stack);
bool	is_sorted(t_node *stack);
int		stack_size(t_node *stack);
void	error_exit(t_node **a);
void	swap(t_node **a, t_node **b, char *cmd);
void	push_func(t_node **src, t_node **dst);
void	rotate(t_node **a, t_node **b, char *cmd);
void	reverse_rotate(t_node **a, t_node **b, char *cmd);
void	move(t_node **first, t_node **second, char *cmd);

#endif
