/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:03:35 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/30 11:42:54 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int free_stack(t_node **a)
{
    t_node	*tmp;

    while (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        free(tmp);
    }
    return (1);
}

int free_array(char **argv)
{
    int	i;

    i = 0;
    while (argv[i])
        free(argv[i++]);
    free(argv);
    return (1);
}

long    ft_atol(const char *str)
{
    long    nbr;
    int     sign;

    nbr = 0;
    sign = 1;
    while (*str == 32 || (*str >= 9 && *str <= 13))
        ++str;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        ++str;
    }
    while (*str >= '0' && *str <= '9')
    {
        nbr = nbr * 10 + (*str - '0');
        ++str;
    }
    return (nbr * sign);
}
