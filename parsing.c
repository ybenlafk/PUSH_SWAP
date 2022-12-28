/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:02:23 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/27 21:24:19 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	over_int(char **av)
{
	int		i;
	long	j;

	i = 0;
	while (av[i])
	{
		j = ft_atoi(av[i]);
		if (j > INT_MAX || j < INT_MIN)
			return (0);
		i++;
	}
	return (i);
}

int	all_int(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (!is_digit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	dup_int(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	parsing(int ac, char **av, t_stack **stc)
{
	t_var	p;

	p.tmp = NULL;
	p.i = 0;
	p.s = ft_strjoin(ac - 1, av + 1, " ");
	if (!p.s)
		return (free(p.s), freeall(stc), exit(1));
	p.str = ft_split(p.s, ' ');
	free(p.s);
	if (ac == 2)
		error(p.str, stc);
	if (!all_int(p.str) || !over_int(p.str) || !dup_int(p.str))
	{
		write(2, "Error\n", 6);
		return (freedom(p.str), freeall(stc), exit(1));
	}
	while (p.str[p.i])
	{
		ft_lstadd_back(stc, ft_lstnew(ft_atoi(p.str[p.i++])));
		if (p.tmp == NULL)
			p.tmp = *stc;
	}
	freedom(p.str);
	*stc = p.tmp;
}
