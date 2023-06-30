/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:48:40 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/23 11:26:16 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nstr(char *number)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (number[i])
	{
		if (number[i] != ' ')
			count++;
		while (number[i] && number[i] != ' ')
			i++;
		if (number[i])
			i++;
	}
	return (count);
}

int	ft_len(char *number)
{
	int	i;

	i = 0;
	while (number[i] && number[i] != ' ')
		i++;
	return (i);
}

void	ft_free(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		free(d[i++]);
	free(d);
}

char	**ft_split(char *number, int *argc)
{
	char	**d;

	if (!number)
		return (NULL);
	*argc = ft_nstr(number) + 1;
	if (*argc == 1)
		exit(0);
	d = malloc(sizeof(char *) * (*argc + 1));
	if (!d)
		return (NULL);
	d[*argc] = 0;
	d[0] = malloc(sizeof(char) * 2);
	if (!d[0])
		return (ft_free(d), NULL);
	d[0][0] = 'x';
	d[0][1] = '\0';
	return (ft_splitexec(number, d));
}

char	**ft_splitexec(char *number, char **d)
{
	int		i;

	i = 1;
	while (*number)
	{
		if (*number != ' ')
		{
			d[i] = ft_substr(number, ft_len(number));
			if (!d[i++])
				return (ft_free(d), NULL);
			number += ft_len(number);
		}
		else
			number++;
	}
	return (d);
}
