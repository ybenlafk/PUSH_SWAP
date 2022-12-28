/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:58:04 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 16:08:48 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swp_ss(t_stack **a, t_stack **b)
{
	if (!*a && !*b)
		return ;
	swp(a);
	swp(b);
}

void	alluc(t_stack **a, t_stack **b)
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

void	alluc_(t_stack **a, t_stack **b, t_stack *tmp)
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

void	puh(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (*b == NULL && *a)
		alluc(a, b);
	else
		if (*a)
			alluc_(a, b, tmp);
	free(tmp);
}
