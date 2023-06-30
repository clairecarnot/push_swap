/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:48:40 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/23 11:00:50 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_order_check(t_list *a)
{
	t_list	*p;
	int		i;
	int		size_a;

	size_a = ft_lstsize(&a);
	if (size_a < 2)
		return (1);
	while (a)
	{
		i = a->value;
		p = a->next;
		while (p)
		{
			if (p->value < i)
				return (0);
			p = p->next;
		}
		a = a->next;
	}
	return (1);
}

char	*ft_substr(char *number, int len)
{
	char	*num;
	int		i;

	i = 0;
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	while (i < len)
	{
		num[i] = number[i];
		i++;
	}
	num[i] = '\0';
	return (num);
}

void	ft_three(t_list **a, int size)
{
	t_list	*tmp;

	tmp = (*a)->next;
	if (size == 2)
		swap_a(*a);
	else if (ft_getmin(a)->value == (*a)->value)
	{
		swap_a(*a);
		rotate_a(a);
	}
	else if (ft_getmin(a)->value == tmp->value)
	{
		tmp = tmp->next;
		if ((*a)->value > tmp->value)
			rotate_a(a);
		else
			swap_a(*a);
	}
	else
	{
		if ((*a)->value > tmp->value)
			swap_a(*a);
		rev_rotate_a(a);
	}
}

void	ft_ten(t_list **a, t_list **b)
{
	t_list	*min_a;

	while (ft_lstsize(a) >= 4)
	{
		ft_posinit(a, b);
		min_a = ft_getmin(a);
		ft_down_to_three(a, b, min_a, ft_lstsize(a));
	}
	if (ft_order_check(*a) == 0)
		ft_three(a, ft_lstsize(a));
	while (ft_lstsize(b))
		push_a(b, a);
}

void	ft_down_to_three(t_list **a, t_list **b, t_list *min_a, int size_a)
{
	if (min_a->pos - 1 < size_a - min_a->pos + 1)
	{
		while (min_a->pos > 1)
		{
			rotate_a(a);
			min_a->pos--;
		}
	}
	else
	{
		while (size_a - min_a->pos + 1 > 0)
		{
			rev_rotate_a(a);
			min_a->pos++;
		}
	}
	push_b(a, b);
}
