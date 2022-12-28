/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:11:49 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/28 10:42:36 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	scapes(char *str, int *i)
{
	while (str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\v' || str[*i] == '\f'
		|| str[*i] == '\r' || str[*i] == ' ')
		(*i)++;
}

long	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	scapes((char *)str, &i);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}

t_stack	*last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	front(t_stack **lst, t_stack *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	delast(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}
