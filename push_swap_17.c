/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_17.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:58:21 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/06 19:54:51 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_last_swap_becomes_ordered_list(t_l *l, t_op *op)
{
	if ((l->la[0] == 0) && (l->la[l->ct_a - 1] == 1))
	{
		l->la[0] = 1;
		l->la[l->ct_a -1] = 0;
		if (ordered_list(l))
		{
			l->la[0] = 0;
			l->la[l->ct_a - 1] = 1;
			exop(RRA, 1, op, l);
			exop(SA, 1, op, l);
			return (1);
		}
		l->la[0] = 0;
		l->la[l->ct_a -1] = 1;
	}
	return (0);
}

/*
check if already ordered list (not processing needed)
if yes, least_order_top_a(l,op), then return (0);
then test,
	l->la[0] swap with l->la[l->ct_a - 1], 
check if l->la is_ordered(l), 
swap back la[0], la[l->ct_a - 1]
if ordered,
	exop(rra) then exop(sa)
	to effect the swap
	lease_order_top_a(l, op)
	return (0)

return (1)
*/
int	further_processing_needed(t_l *l, t_op *op)
{
	if (ordered_list(l))
	{
		least_order_top_a(l, op);
		return (0);
	}
	if ((l->la[0] == 1) && (l->la[1] == 0))
	{
		l->la[0] = 0;
		l->la[1] = 1;
		if (ordered_list(l))
		{
			l->la[0] = 1;
			l->la[1] = 0;
			exop(SA, 1, op, l);
			return (0);
		}
		l->la[0] = 1;
		l->la[1] = 0;
	}
	if (first_last_swap_becomes_ordered_list(l, op))
		return (0);
	return (1);
}

void	p_op_list(char *oplist, int k)
{
	int		i;

	i = 0;
	while (i < k)
	{
		op_str2(oplist[i]);
		i++;
	}
}

void	w_err(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

void	validate_arg2_elements(char *s, t_sl *sl, t_l *l, int *error)
{
	int	val;

	if (validarg((s), sl))
	{
		val = atoi(s);
		ins_sort(val, sl);
		l->la[l->ct_a] = val;
		(l->ct_a)++;
	}
	else
		*error = 1;
}
