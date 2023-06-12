/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:03:20 by luide-so          #+#    #+#             */
/*   Updated: 2023/06/12 12:22:02 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

static void	move_checker(t_node **first, t_node **second, char *cmd)
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
}

static void	checker(t_node **a, t_node **b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		move_checker(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	free(cmd);
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
	checker(&a, &b);
	if (is_sorted(a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
