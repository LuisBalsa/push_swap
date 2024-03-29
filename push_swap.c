/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:02:39 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/10 11:16:07 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_init(t_node **a, char **argv, bool argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, argc_2);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv, argc_2);
		append_node(a, (int)nbr);
		++i;
	}
	if (argc_2)
		free_array(argv);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		error_exit();
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + !(argc == 2), argc == 2);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			move(&a, &b, SA);
		else if (stack_size(a) == 3)
			sort_tree(&a);
		else
			sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
