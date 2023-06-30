/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:24:54 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/22 17:34:40 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_firstpush(t_list **a, t_list **b, int med_a, int max_a)
{
	int	size;

	size = ft_lstsize(a);
	while (size)
	{
		if ((*a)->value != max_a)
		{
			push_b(a, b);
			if ((*b)->value > med_a)
				rotate_b(b);
		}
		else
			rotate_a(a);
		size--;
	}
}

void	ft_sortloop(t_list **a, t_list **b, int max_a)
{
	t_list	*tmp_b;
	t_list	*cheapest_b;
	int		cost_b;
	int		cost_tmp;

	while (*b)
	{
		cheapest_b = *b;
		ft_posinit(a, b);
		cost_b = ft_getcost(b, b, a, max_a);
		tmp_b = (*b)->next;
		while (tmp_b)
		{
			cost_tmp = ft_getcost(b, &tmp_b, a, max_a);
			if (cost_tmp < cost_b)
			{
				cost_b = cost_tmp;
				cheapest_b = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		ft_moveab(a, b, &cheapest_b);
	}
	ft_finalsort(a, b);
}

void	ft_posinit(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	i = 1;
	while (a)
	{
		a->pos = i;
		a = a->next;
		i++;
	}
	i = 1;
	while (b)
	{
		b->pos = i;
		b = b->next;
		i++;
	}
}

int	ft_getcost(t_list **stack_b, t_list **b, t_list **a, int max_a)
{
	int		size_b;
	int		size_a;
	int		cost_b;
	t_list	*major_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(stack_b);
	if ((*b)->pos - 1 < size_b - (*b)->pos + 1)
		cost_b = (*b)->pos - 1;
	else
		cost_b = size_b - (*b)->pos + 1;
	major_b = ft_getmajor(b, a, max_a);
	if (major_b->pos - 1 < size_a - major_b->pos + 1)
		cost_b += major_b->pos - 1;
	else
		cost_b += size_a - major_b->pos + 1;
	return (cost_b);
}

t_list	*ft_getmajor(t_list **stack_b, t_list **stack_a, int max_a)
{
	int		major_tmp;
	t_list	*pos_major;
	t_list	*a;

	a = *stack_a;
	(*stack_b)->majorpos = a->pos;
	pos_major = *stack_a;
	major_tmp = max_a;
	while (a)
	{
		if (a->value > (*stack_b)->value && a->value <= major_tmp)
		{
			major_tmp = a->value;
			(*stack_b)->majorpos = a->pos;
			pos_major = a;
		}
		a = a->next;
	}
	return (pos_major);
}
