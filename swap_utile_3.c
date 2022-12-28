/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utile_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:11:49 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 16:13:44 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		write(1, &*s++, 1);
}

void	freeallstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	freeall(t_stack **p)
{
	t_stack	*tmp;

	while (*p)
	{
		tmp = *p;
		*p = (*p)->next;
		free(tmp);
	}
}

void	freaction(t_action **p)
{
	t_action	*tmp;

	while (*p)
	{
		tmp = *p;
		*p = (*p)->next;
		free(tmp);
	}
}

void	display_inst(t_action **t)
{
	char		*rb;
	char		*ra;
	t_action	*tmp;

	ra = "ra\n";
	rb = "rb\n";
	tmp = *t;
	while (tmp->next)
	{
		if ((tmp->data == rb && tmp->next->data == ra)
			|| (tmp->data == ra && tmp->next->data == rb))
		{
			ft_putstr("rr\n");
			tmp = tmp->next;
			tmp = tmp->next;
		}
		else
		{
			ft_putstr(tmp->data);
			tmp = tmp->next;
		}
	}
	ft_putstr(tmp->data);
	freaction(t);
}
