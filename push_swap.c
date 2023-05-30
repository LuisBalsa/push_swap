/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:02:39 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/31 00:37:19 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	printarray(t_node *a)
{
	while (a)
	{
		ft_putnbr_fd(a->value, 1);
		write(1, "\n", 1);
		a = a->next;
	}
}

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
	(void) argc_2, (void) argv, (void) a;
	if (argc_2)
		free_array(argv);
	free_stack(a);
	write(2, "Error\n", 6);
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
	//t_node	*b;

	a = NULL;
	//b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + !(argc == 2), argc == 2);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_tree(&a);
		else
			printarray(a); //push_swap(&a, &b);
	}
	printf("\nResultado:\n");
	printarray(a);
	free_stack(&a);
	return (0);
}
