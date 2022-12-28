/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 23:02:06 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/26 21:37:53 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int nb)
{
	t_stack	*p;

	p = (t_stack *)malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	p->nb = nb;
	p->next = NULL;
	return (p);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			p = ft_lstlast(*lst);
			p->next = new;
		}
	}
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*p;

	if (lst)
	{
		while (*lst)
		{
			p = *lst;
			*lst = p->next;
			free(p);
		}
		p = NULL;
	}
}
