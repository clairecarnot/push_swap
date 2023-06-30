/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:42:05 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/22 17:30:44 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mutual_rotate(t_list **a, t_list **b, t_list **cheapest_b)
{
	while (((*cheapest_b)->majorpos > 1) && ((*cheapest_b)->pos > 1))
	{
		rotate_ab(a, b);
		(*cheapest_b)->majorpos--;
		(*cheapest_b)->pos--;
	}
}

void	ft_mutual_revrotate(t_list **a, t_list **b, t_list **cheapest_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while ((size_a - (*cheapest_b)->majorpos + 1 > 0)
		&& (size_b - (*cheapest_b)->pos + 1 > 0))
	{
		rev_rotate_ab(a, b);
		(*cheapest_b)->majorpos++;
		(*cheapest_b)->pos++;
	}
}
