/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:53:50 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 16:11:52 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	retate(t_stack **a, t_action **t, int state)
{
	t_stack	*new;
	t_stack	*ptr;

	if (ft_lstsize(*a) <= 1)
		return ;
	new = newnode((*a)->nb);
	new->index = (*a)->index;
	ptr = *a;
	*a = (*a)->next;
	back(a, new);
	if (!state)
	{
		(*t)->next = lstnew("ra\n");
		*t = (*t)->next;
	}
	if (state == 1)
	{
		(*t)->next = lstnew("rb\n");
		*t = (*t)->next;
	}
	free(ptr);
}

void	rev_retate(t_stack **a, t_action **t, int state)
{
	t_stack	*new;
	t_stack	*tmp;

	if (ft_lstsize(*a) <= 1)
		return ;
	tmp = *a;
	tmp = last(tmp);
	new = newnode(tmp->nb);
	new->index = tmp->index;
	front(a, new);
	delast(a);
	if (!state)
	{
		(*t)->next = lstnew("rra\n");
		*t = (*t)->next;
	}
	if (state == 1)
	{
		(*t)->next = lstnew("rrb\n");
		*t = (*t)->next;
	}
}

void	rrr_op(t_stack **a, t_stack **b, t_action **t)
{
	if (!*a && !*b)
		return ;
	rev_retate(a, t, 2);
	rev_retate(b, t, 2);
	(*t)->next = lstnew("rrr\n");
	*t = (*t)->next;
}

void	rr_op(t_stack **a, t_stack **b, t_action **t)
{
	if (!*a && !*b)
		return ;
	retate(a, t, 2);
	retate(b, t, 2);
	(*t)->next = lstnew("rr\n");
	*t = (*t)->next;
}
