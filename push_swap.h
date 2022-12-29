/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:27:04 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/29 21:32:16 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct stack
{
	int				nb;
	int				index;
	struct stack	*next;
}	t_stack;

typedef struct action
{
	char			*data;
	struct action	*next;
}	t_action;

typedef struct var
{
	t_stack		*stc;
	t_stack		**a;
	t_stack		**b;
	t_stack		*ba;
	t_action	**t;
	t_action	*ta;
	t_stack		*tmp;
	t_action	*tmpt;
	t_stack		*min;
	t_stack		*ln;
	char		*s;
	char		**str;
	int			i;
	int			j;
	int			pos;
	int			ex;
	int			len;
	int			cut;
	int			ref;
	int			nb1;
	int			nb2;
	int			nb3;
}	t_var;

long		ft_atoi(const char *str);
int			ft_lstsize(t_stack *lst);
int			check_sorted(t_stack **a);
int			get_pos(t_stack *tmp, int j);
int			count_instr(int len, int pos);
int			is_digit(int c);
int			over_int(char **av);
int			all_int(char **av);
int			dup_int(char **av);
int			count_instr(int len, int pos);
size_t		ft_strlen(const char *str);
t_stack		*last(t_stack *lst);
t_stack		*addnode(int nb, t_stack *list);
t_stack		*newnode(int nb);
t_stack		*indexed(t_stack **a);
t_action	*lstnew(char *data);
t_stack		*ft_lstnew(int nb);
void		back(t_stack **lst, t_stack *new);
void		front(t_stack **lst, t_stack *new);
void		rev_retate(t_stack **a, t_action **t, int state);
void		retate(t_stack **a, t_action **t, int state);
void		rrr_op(t_stack **a, t_stack **b, t_action **t);
void		rr_op(t_stack **a, t_stack **b, t_action **t);
void		swap(t_stack **a, t_action **t, int state);
void		swap_ss(t_stack **a, t_stack **b, t_action **t);
void		delast(t_stack **a);
void		three_elem(t_stack **stc, t_action **t);
void		four_elem(t_stack **a, t_action **t);
void		five_elem(t_stack **stc, t_action **t);
void		push(t_stack **a, t_stack **b, t_action **t, int state);
void		sort_algo(t_stack **a, t_action **t, int chunks);
void		six_elem(t_stack **stc, t_action **t);
void		display_inst(t_action **t);
void		ft_putstr(char *s);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		parsing(int ac, char **av, t_stack **stc);
char		**ft_split(char const	*s, char c);
char		*ft_strjoin(int size, char **strs, char *sep);
void		ft_lstclear(t_stack **lst);
void		freeall(t_stack **p);
void		freaction(t_action **p);
char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ftstrjoin(char *s1, char *s2);
char		*ft_strdup(const char *src);
void		push_it(t_stack **a, int cut, t_action **t, t_var *p);
void		push_up(t_stack **a, t_var *var, t_action **t);
void		freedom(char **p);
void		error(char **av, t_stack **stc);
void		rab(t_stack **a);
void		rrab(t_stack **a);
void		oprrr(t_stack **a, t_stack **b);
void		oprr(t_stack **a, t_stack **b);
void		swp(t_stack **a);
void		swp_ss(t_stack **a, t_stack **b);
void		puh(t_stack **a, t_stack **b);

#endif
