/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:53:40 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/26 16:03:05 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **a, t_action **t, int state)
{
	int	i;
	int	j;

	if (ft_lstsize(*a) <= 1)
		return ;
	i = (*a)->nb;
	j = (*a)->next->nb;
	(*a)->nb = j;
	(*a)->next->nb = i;
	if (!state)
	{
		(*t)->next = lstnew("sa\n");
		*t = (*t)->next;
	}
	if (state == 1)
	{
		(*t)->next = lstnew("sb\n");
		*t = (*t)->next;
	}
}

void	swap_ss(t_stack **a, t_stack **b, t_action **t)
{
	if (!*a && !*b)
		return ;
	swap(a, t, 2);
	swap(b, t, 2);
	(*t)->next = lstnew("ss\n");
	*t = (*t)->next;
}
