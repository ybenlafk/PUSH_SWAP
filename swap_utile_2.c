/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utile_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:11:49 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/26 20:58:36 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			p = last(*lst);
			p->next = new;
		}
	}
}

t_stack	*addnode(int nb, t_stack *list)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	if (list)
		list->next = s;
	s->nb = nb;
	s->next = NULL;
	return (s);
}

t_stack	*newnode(int nb)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->nb = nb;
	s->next = NULL;
	return (s);
}

t_action	*lstnew(char *data)
{
	t_action	*s;

	s = (t_action *)malloc(sizeof(t_action));
	if (!s)
		return (NULL);
	s->data = data;
	s->next = NULL;
	return (s);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*tmp;
	int		len;

	tmp = lst;
	len = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}
