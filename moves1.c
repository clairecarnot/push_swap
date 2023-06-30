/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:14:36 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/22 17:36:07 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moveab(t_list **a, t_list **b, t_list **cheapest_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	if (size_a > 1 && size_b > 1)
	{
		if (((*cheapest_b)->majorpos - 1
				<= size_a - (*cheapest_b)->majorpos + 1)
			&& ((*cheapest_b)->pos - 1
				<= size_b - (*cheapest_b)->pos + 1))
			ft_mutual_rotate(a, b, cheapest_b);
		else if (((*cheapest_b)->majorpos - 1
				>= size_a - (*cheapest_b)->majorpos + 1)
			&& ((*cheapest_b)->pos - 1
				>= size_b - (*cheapest_b)->pos + 1))
			ft_mutual_revrotate(a, b, cheapest_b);
	}
	ft_movea(a, cheapest_b);
	ft_moveb(a, b, cheapest_b);
}

void	ft_movea(t_list **a, t_list **cheapest_b)
{
	int	size_a;

	size_a = ft_lstsize(a);
	if (size_a > 1)
	{
		if ((*cheapest_b)->majorpos - 1 < size_a - (*cheapest_b)->majorpos + 1)
		{	
			while ((*cheapest_b)->majorpos > 1)
			{
				rotate_a(a);
				(*cheapest_b)->majorpos--;
			}
		}	
		else
		{
			while (size_a - (*cheapest_b)->majorpos + 1 > 0)
			{
				rev_rotate_a(a);
				(*cheapest_b)->majorpos++;
			}
		}
	}
}

void	ft_moveb(t_list **a, t_list **b, t_list **cheapest_b)
{
	int	size_b;

	size_b = ft_lstsize(b);
	if (size_b > 1)
	{
		if ((*cheapest_b)->pos - 1 < size_b - (*cheapest_b)->pos + 1)
		{	
			while ((*cheapest_b)->pos > 1)
			{
				rotate_b(b);
				(*cheapest_b)->pos--;
			}
		}	
		else
		{
			while (size_b - (*cheapest_b)->pos + 1 > 0)
			{
				rev_rotate_b(b);
				(*cheapest_b)->pos++;
			}
		}
	}
	push_a(b, a);
}

t_list	*ft_getmin(t_list **a)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *a;
	min = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_finalsort(t_list **a, t_list **b)
{
	t_list	*min;
	int		size_a;

	ft_posinit(a, b);
	size_a = ft_lstsize(a);
	min = ft_getmin(a);
	if (min->pos - 1 < size_a - min->pos + 1)
	{
		while (min->pos > 1)
		{
			rotate_a(a);
			min->pos--;
		}
	}
	else
	{
		while (size_a - min->pos + 1)
		{
			rev_rotate_a(a);
			min->pos++;
		}
	}
}
