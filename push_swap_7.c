/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:37:53 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:40:33 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exrotate(int type, t_l *l)
{
	if (type == RA)
		ra(l);
	else if (type == RB)
		rb(l);
	else if (type == RR)
		rr(l);
	else if (type == RRA)
		rra(l);
	else if (type == RRB)
		rrb(l);
	else if (type == RRR)
		rrr(l);
}
/*
char	*op_str(int type, char *s)
{
	char	*type_str;

	type_str = OP_STR;
	ft_strlcpy(s, type_str + (type * 3), 4);
	return (s);
}
*/

void	op_str2(int type)
{
	if (type == 0)
		write(1, "sa\n", 3);
	else if (type == 1)
		write(1, "sb\n", 3);
	else if (type == 2)
		write(1, "pa\n", 3);
	else if (type == 3)
		write(1, "pb\n", 3);
	else if (type == 4)
		write(1, "ra\n", 3);
	else if (type == 5)
		write(1, "rb\n", 3);
	else if (type == 6)
		write(1, "rr\n", 3);
	else if (type == 7)
		write(1, "ss\n", 3);
	else if (type == 8)
		write(1, "rra\n", 4);
	else if (type == 9)
		write(1, "rrb\n", 4);
	else if (type == 10)
		write(1, "rrr\n", 4);
}

void	exop(int type, int repeat, t_op *op, t_l *l)
{
	int	i;

	i = 0;
	while (i < repeat)
	{
		if (type == SA)
			sa(l);
		else if (type == SB)
			sb(l);
		else if (type == PA)
			pa(l);
		else if (type == PB)
			pb(l);
		else if (type == SS)
			ss(l);
		else
			exrotate(type, l);
		log_op(type, op);
		i++;
	}
}
/*
void	p_sl(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->ct)
	{
		ft_printf("%d[%s%d%s]", i, GREEN, sl->n[i], DEFAULT);
		i++;
	}
	ft_printf("\n");
}
*/

void	push_sl(int dst, int src, int cnt, t_sl *sl)
{
	int	i;

	i = cnt - 1;
	while (i >= 0)
	{
		sl->n[dst + i] = sl->n[src + i];
		i--;
	}
}

void	ins_sort(int val, t_sl *sl)
{
	int	i;

	i = 0;
	while ((i < sl->ct) && (val > sl->n[i]))
		i++;
	if ((sl->ct - i) > 0)
	{
		push_sl(i + 1, i, sl->ct - i, sl);
	}
	(sl->n)[i] = val;
	(sl->ct)++;
}
