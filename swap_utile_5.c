/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utile_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:11:49 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/26 15:01:20 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while ((*a))
	{
		(*a)->index = -1;
		(*a) = (*a)->next;
	}
	*a = tmp;
}

void	check_if(t_stack **a, t_var *var)
{
	while (*a)
	{
		if ((*a)->index == -1 && var->min->index == -1
			&& (*a)->nb < var->min->nb)
			var->min = *a;
		*a = (*a)->next;
	}
}

t_stack	*indexed(t_stack **a)
{
	t_var	var;

	var.i = 0;
	var.tmp = *a;
	var.ln = *a;
	mark(a);
	while (var.ln)
	{
		var.min = *a;
		check_if(a, &var);
		var.min->index = var.i++;
		*a = var.tmp;
		while (*a)
		{
			if ((*a)->index == -1)
			{
				var.min = *a;
				break ;
			}
			*a = (*a)->next;
		}
		var.ln = var.ln->next;
	}
	return (var.tmp);
}

void	push_it(t_stack **a, int cut, t_action **t, t_var *p)
{
	while (p->tmp && p->tmp->index > cut)
	{
		p->tmp = p->tmp->next;
		p->pos++;
	}
	if (p->pos < p->ex / 2)
		while (p->j++ < p->pos)
			retate (a, t, 0);
	else
		while (p->j++ < p->ex - p->pos)
			rev_retate (a, t, 0);
}

void	push_up(t_stack **a, t_var *var, t_action **t)
{
	t_var	p;

	p.i = 0;
	while (p.i < var->ref && *a)
	{
		p.ex = ft_lstsize(*a);
		p.pos = 0;
		p.j = 0;
		p.tmp = *a;
		push_it(a, var->cut, t, &p);
		if (p.tmp->index < var->cut - (var->ref / 2))
			push(a, &var->ba, t, 1);
		else
		{
			push(a, &var->ba, t, 1);
			retate(&var->ba, t, 1);
		}
		p.i++;
	}
}
