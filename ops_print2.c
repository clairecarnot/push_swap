/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_print2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:26:53 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/16 11:53:56 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a)
{
	if (*a && (*a)->next)
		write(1, "ra\n", 3);
	ft_rotate(a);
}

void	rotate_b(t_list **b)
{
	if (*b && (*b)->next)
		write(1, "rb\n", 3);
	ft_rotate(b);
}

void	rotate_ab(t_list **a, t_list **b)
{
	if ((*a && (*a)->next) || (*b && (*b)->next))
		write(1, "rr\n", 3);
	ft_rotate(a);
	ft_rotate(b);
}

void	rev_rotate_a(t_list **a)
{
	if (*a && (*a)->next)
		write(1, "rra\n", 4);
	ft_rev_rotate(a);
}

void	rev_rotate_b(t_list **b)
{
	if (*b && (*b)->next)
		write(1, "rrb\n", 4);
	ft_rev_rotate(b);
}
