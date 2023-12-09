/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker6_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:02:16 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 03:17:50 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	validarg(char *s, t_sl *sl)
{
	int	i;
	int	num;
	int	error;

	num = atoi_errdetect(s, &error);
	if (error)
	{
		return (0);
	}
	i = 0;
	while (i < sl->ct)
	{
		if (num == sl->n[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
