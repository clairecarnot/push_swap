/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_keyval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:36:48 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/22 16:14:10 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tab_init(t_list *a, int *tab, int size)
{
	int	i;

	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = a->value;
		a = a->next;
		i++;
	}
	ft_tab_sort(tab, size);
	return (tab);
}

int	*ft_tab_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
				ft_sort(&tab[j], &tab[i]);
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_sort(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	ft_getmedian(int *tab, int size)
{
	int	median;

	if (size % 2 != 0)
		median = tab[size / 2];
	else
		median = (tab[size / 2 - 1] + tab[size / 2]) / 2;
	return (median);
}

int	ft_getmax(int *tab, int size)
{
	int	max;
	int	i;

	max = tab[0];
	i = 1;
	while (i < size)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

/************************************************************
void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
************************************************************/
