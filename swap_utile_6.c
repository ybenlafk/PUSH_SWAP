/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utile_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:11:49 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/28 10:43:37 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_stack *tmp, int j)
{
	int	i;

	i = 1;
	while (tmp && tmp->index != j)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	check_sorted(t_stack **a)
{
	t_stack	*tmp;

	if (ft_lstsize(*a) <= 1)
		return (0);
	tmp = *a;
	while ((*a)->next)
	{
		if ((*a)->nb > (*a)->next->nb)
			return (*a = tmp, 0);
		*a = (*a)->next;
	}
	return (*a = tmp, 1);
}

void	freedom(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

int	cunt(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	error(char **av, t_stack **stc)
{
	if (!all_int(av) || !over_int(av) || !dup_int(av))
		return (write(2, "Error\n", 6), free(av), freeall(stc), exit(0));
	else if (cunt(av) <= 1)
		exit(0);
}
