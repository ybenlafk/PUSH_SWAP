/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:56:13 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 16:07:38 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rab(t_stack **a)
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
	free(ptr);
}

void	rrab(t_stack **a)
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
}

void	oprrr(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
		return ;
	rrab(a);
	rrab(b);
}

void	oprr(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
		return ;
	rab(a);
	rab(b);
}

void	swp(t_stack **a)
{
	int	i;
	int	j;

	if (ft_lstsize(*a) <= 1)
		return ;
	i = (*a)->nb;
	j = (*a)->next->nb;
	(*a)->nb = j;
	(*a)->next->nb = i;
}
