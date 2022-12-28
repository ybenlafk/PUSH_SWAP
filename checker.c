/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:21:04 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 16:05:41 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	intrs_do(t_stack **a, t_stack **b, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		swp(a);
	else if (!ft_strcmp(s, "sb\n"))
		swp(b);
	else if (!ft_strcmp(s, "ss\n"))
		swp_ss(a, b);
	else if (!ft_strcmp(s, "pa\n"))
		puh(b, a);
	else if (!ft_strcmp(s, "pb\n"))
		puh(a, b);
	else if (!ft_strcmp(s, "ra\n"))
		rab(a);
	else if (!ft_strcmp(s, "rb\n"))
		rab(b);
	else if (!ft_strcmp(s, "rr\n"))
		oprr(b, a);
	else if (!ft_strcmp(s, "rra\n"))
		rrab(a);
	else if (!ft_strcmp(s, "rrb\n"))
		rrab(b);
	else if (!ft_strcmp(s, "rrr\n"))
		oprrr(a, b);
	else
		return (write(2, "Error\n", 6), freeall(a), exit(0));
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		*s;

	parsing(ac, av, &a);
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		intrs_do(&a, &b, s);
		free(s);
	}
	if (check_sorted(&a) && ft_lstsize(b) <= 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
