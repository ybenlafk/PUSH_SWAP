/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:47:02 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 16:10:29 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cases(t_var *p)
{
	if (p->len == 2)
		swap(&p->stc, &p->ta, 0);
	else if (p->len == 3)
		three_elem(&p->stc, &p->ta);
	else if (p->len == 4)
		four_elem(&p->stc, &p->ta);
	else if (p->len == 5)
		five_elem(&p->stc, &p->ta);
	else if (p->len <= 100)
		sort_algo(&p->stc, &p->ta, 5);
	else
		sort_algo(&p->stc, &p->ta, 10);
}

void	push_swap(int ac, char **av)
{
	t_var	p;

	p.stc = NULL;
	p.ta = lstnew("");
	p.tmpt = p.ta;
	parsing(ac, av, &p.stc);
	if (check_sorted(&p.stc))
	{
		freaction(&p.ta);
		freeall(&p.stc);
		exit(1);
	}
	p.stc = indexed(&p.stc);
	p.len = ft_lstsize(p.stc);
	cases(&p);
	display_inst(&p.tmpt);
	freeall(&p.stc);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		push_swap(ac, av);
	return (0);
}
