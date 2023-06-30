/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_print1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:12:58 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/16 11:43:43 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *a)
{
	if (a && a->next)
		write(1, "sa\n", 3);
	ft_swap(a);
}

void	swap_b(t_list *b)
{
	if (b && b->next)
		write(1, "sb\n", 3);
	ft_swap(b);
}

void	swap_ab(t_list *a, t_list *b)
{
	if ((a && a->next) || (b && b->next))
		write(1, "ss\n", 3);
	ft_swap(a);
	ft_swap(b);
}

void	push_a(t_list **b, t_list **a)
{
	if (*b)
		write(1, "pa\n", 3);
	ft_push(b, a);
}

void	push_b(t_list **a, t_list **b)
{
	if (*a)
		write(1, "pb\n", 3);
	ft_push(a, b);
}
