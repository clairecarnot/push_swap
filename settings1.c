/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:11:06 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/23 11:29:33 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_params(char *number)
{
	long int	n;
	int			i;

	i = 0;
	if (number[i] == 45 && number[i + 1])
		i++;
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9' || i > 10)
			return (1);
		i++;
	}
	n = ft_atoi(number);
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

int	ft_dupl_check(t_list *a)
{
	int		i;
	t_list	*p;

	while (a)
	{
		i = a->value;
		p = a->next;
		while (p)
		{
			if (i == p->value)
				return (1);
			p = p->next;
		}
		a = a->next;
	}
	return (0);
}

t_list	*ft_stack_init(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*tmp;

	i = 0;
	while (++i < argc)
	{
		if (ft_check_params(argv[i]))
			return (NULL);
	}
	a = ft_lstnew(argv[1]);
	if (!a)
		return (NULL);
	tmp = a;
	i = 2;
	while (i < argc)
	{
		tmp->next = ft_lstnew(argv[i]);
		if (!tmp->next)
			return (ft_lstclear(&a), NULL);
		tmp = tmp->next;
		i++;
	}
	return (a);
}

void	ft_push_swap(t_list **a, t_list **b)
{
	int	size_a;
	int	*tab;
	int	med_a;
	int	max_a;

	size_a = ft_lstsize(a);
	if (size_a < 4)
		ft_three(a, size_a);
	else if (size_a < 11)
		ft_ten(a, b);
	else
	{
		tab = NULL;
		tab = tab_init(*a, tab, size_a);
		if (!tab)
			return ;
		med_a = ft_getmedian(tab, size_a);
		max_a = ft_getmax(tab, size_a);
		free(tab);
		ft_firstpush(a, b, med_a, max_a);
		ft_sortloop(a, b, max_a);
	}
	ft_lstclear(a);
	ft_lstclear(b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**args;

	b = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			args = ft_split(argv[1], &argc);
			if (!args)
				return (write(2, "Error\n", 6), 1);
			a = ft_stack_init(argc, args);
			ft_free(args);
		}
		else
			a = ft_stack_init(argc, argv);
		if (!a || ft_dupl_check(a))
			return (ft_lstclear(&a), write(2, "Error\n", 6), 1);
		if (ft_order_check(a))
			return (ft_lstclear(&a), 0);
		ft_push_swap(&a, &b);
	}
	return (0);
}
