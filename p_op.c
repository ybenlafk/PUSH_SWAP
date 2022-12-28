/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:55:53 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 16:11:25 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alloc(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	*b = (t_stack *)malloc(sizeof(t_stack));
	ptr = *a;
	(*b)->nb = (*a)->nb;
	(*b)->index = (*a)->index;
	(*b)->next = NULL;
	(*a) = (*a)->next;
	free(ptr);
}

void	alloc_(t_stack **a, t_stack **b, t_stack *tmp)
{
	t_stack	*ptr;

	ptr = *a;
	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->nb = (*a)->nb;
	tmp->index = (*a)->index;
	tmp->next = NULL;
	front(b, tmp);
	(*a) = (*a)->next;
	free(ptr);
}

void	push(t_stack **a, t_stack **b, t_action **t, int state)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*b == NULL && *a)
		alloc(a, b);
	else
		if (*a)
			alloc_(a, b, tmp);
	if (!state)
	{
		(*t)->next = lstnew("pa\n");
		*t = (*t)->next;
	}
	if (state == 1)
	{
		(*t)->next = lstnew("pb\n");
		*t = (*t)->next;
	}
}
