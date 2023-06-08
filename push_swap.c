/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:02:39 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/07 21:46:34 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_repetition(t_node *a, int nbr)
{
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	error_free(t_node **a, char **argv, bool argc_2)
{
	if (argc_2)
		free_array(argv);
	free_stack(a);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static int	error_syntax(char *nbr)
{
	if (*nbr == '-' || *nbr == '+')
		++nbr;
	if (!ft_isdigit(*nbr))
		return (1);
	while (*nbr)
	{
		if (!ft_isdigit(*nbr))
			return (1);
		++nbr;
	}
	return (0);
}

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
