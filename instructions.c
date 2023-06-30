/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:46:11 by ccarnot           #+#    #+#             */
/*   Updated: 2023/06/16 11:51:46 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *stack)
{
	int		tmp;
	t_list	*p;

	if (stack && stack->next)
	{
		p = stack->next;
		tmp = stack->value;
		stack->value = p->value;
		p->value = tmp;
	}
}

void	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (!(*stack_from))
		return ;
	if (!(*stack_to))
	{
		tmp = (*stack_from)->next;
		*stack_to = *stack_from;
		(*stack_to)->next = NULL;
		*stack_from = tmp;
	}
	else
	{
		tmp = *stack_to;
		*stack_to = *stack_from;
		*stack_from = (*stack_from)->next;
		(*stack_to)->next = tmp;
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*newstart;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	newstart = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = tmp;
	*stack = (*stack)->next;
	(*stack)->next = NULL;
	*stack = newstart;
}

void	ft_rev_rotate(t_list **stack)
{
	t_list	*toaddfront;
	t_list	*oldstart;

	if (!(*stack) || !((*stack)->next))
		return ;
	oldstart = *stack;
	toaddfront = (*stack)->next;
	while (toaddfront->next)
	{
		toaddfront = toaddfront->next;
		*stack = (*stack)->next;
	}
	(*stack)->next = NULL;
	ft_lstaddfront(stack, toaddfront);
	toaddfront->next = oldstart;
}
