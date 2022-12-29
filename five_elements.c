/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:36:39 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/29 21:35:06 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elem(t_stack **stc, t_action **t)
{
	t_var	p;

	p.nb1 = (*stc)->nb;
	p.nb2 = (*stc)->next->nb;
	p.nb3 = (*stc)->next->next->nb;
	if (p.nb1 > p.nb2 && p.nb2 < p.nb3 && p.nb3 > (*stc)->nb)
		swap(stc, t, 0);
	else if (p.nb1 > p.nb2 && p.nb2 > p.nb3)
	{
		swap(stc, t, 0);
		rev_retate(stc, t, 0);
	}
	else if (p.nb1 > p.nb2 && p.nb2 < p.nb3 && p.nb3 < (*stc)->nb)
		retate(stc, t, 0);
	else if (p.nb1 < p.nb2 && p.nb2 > p.nb3 && p.nb1 < p.nb3)
	{
		swap(stc, t, 0);
		retate(stc, t, 0);
	}
	else if (p.nb1 < p.nb2 && p.nb2 > p.nb3 && p.nb1 > p.nb3)
		rev_retate(stc, t, 0);
}

int	min_pos(t_stack	*lst)
{
	t_var	p;

	p.i = 1;
	p.pos = p.i;
	p.j = lst->nb;
	lst = lst->next;
	while (lst)
	{
		p.i++;
		if (p.j > lst->nb)
		{
			p.pos = p.i;
			p.j = lst->nb;
		}
		lst = lst->next;
	}
	return (p.pos);
}

void	four_elem(t_stack **a, t_action **t)
{
	t_var	p;

	p.ba = NULL;
	p.pos = min_pos(*a);
	if (p.pos == 2)
	{
		swap(a, t, 0);
	}	
	else if (p.pos == 3)
	{
		retate(a, t, 0);
		swap(a, t, 0);
	}
	else if (p.pos == 4)
		rev_retate(a, t, 0);
	push(a, &p.ba, t, 1);
	three_elem(a, t);
	push(&p.ba, a, t, 0);
	freeall(&p.ba);
}

void	push_min(t_stack **stc, t_stack **b, t_action **t)
{
	t_var	p;

	p.tmp = *stc;
	p.i = p.tmp->nb;
	while (p.tmp)
	{
		if (p.i > p.tmp->nb)
			p.i = p.tmp->nb;
		p.tmp = p.tmp->next;
	}
	while (1)
	{
		if ((*stc)->nb == p.i)
		{
			push(stc, b, t, 1);
			break ;
		}
		else
			retate(stc, t, 0);
	}
}

void	five_elem(t_stack **stc, t_action **t)
{
	t_stack	*b;

	push_min(stc, &b, t);
	four_elem(stc, t);
	push(&b, stc, t, 0);
}
