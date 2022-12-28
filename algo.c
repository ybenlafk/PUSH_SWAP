/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:31:15 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/26 20:09:44 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_in(t_stack **a, t_stack **b, t_action **t, int j)
{
	int	pos;
	int	inst;

	pos = get_pos(*a, j);
	inst = count_instr(ft_lstsize(*a), pos);
	while (inst--)
	{
		if (pos <= ft_lstsize(*a) / 2)
			retate(a, t, 1);
		else
			rev_retate(a, t, 1);
	}
	push(a, b, t, 0);
}

void	push_one(t_stack **a, t_stack **b, t_action **t)
{
	int	j;

	j = ft_lstsize(*a) - 1;
	push_in(a, b, t, j);
}

void	push_two(t_stack **a, t_stack **b, t_action **t)
{
	int	p;
	int	pos;

	p = ft_lstsize(*a) - 1;
	pos = p - 1;
	push_in(a, b, t, pos);
	push_in(a, b, t, p);
	swap(b, t, 0);
}

void	sorted(t_stack **a, t_stack **b, t_action **t)
{
	int	j;
	int	p;
	int	pos;

	j = ft_lstsize(*b) - 1;
	while (j > 0)
	{
		p = get_pos(*b, j);
		pos = get_pos(*b, j - 1);
		if (count_instr(ft_lstsize(*b), p) > count_instr(ft_lstsize(*b), pos))
			push_two(b, a, t);
		else
			push_one(b, a, t);
		j = ft_lstsize(*b) - 1;
	}
	if (j == 0)
		push(b, a, t, 0);
}

void	sort_algo(t_stack **a, t_action **t, int chunks)
{
	t_var	p;

	p.tmp = *a;
	p.ba = NULL;
	p.len = ft_lstsize(*a);
	p.cut = p.len / chunks;
	p.ref = p.len / chunks;
	while (ft_lstsize(*a))
	{
		push_up(a, &p, t);
		p.cut += p.ref;
	}
	sorted(a, &p.ba, t);
	freeall(&p.ba);
}
