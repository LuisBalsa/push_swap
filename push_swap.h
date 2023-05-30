/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:04:51 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/30 18:08:35 by luide-so         ###   ########.fr       */
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
	struct node	*prev;
}				t_node;

int				free_stack(t_node **a);
int				free_array(char **argv);
long			ft_atol(const char *str);
void			append_node(t_node **head, int value);
void			sort_tree(t_node **stack);
bool			is_sorted(t_node *stack);
int				stack_size(t_node *stack);

#endif
