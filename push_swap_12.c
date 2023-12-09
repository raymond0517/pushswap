/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_12.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:49:03 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/07 05:46:21 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* set up parameters in p1 to perform check if elements from stack 'b', ie. the
	first 3 elements or the last 2 elements is in next order with 
	last 'a' element, if so, push the 'b' element of interest to be next with
	the last 'a' element, 
	last 'a' element must be in buildlist before any of the 5 elements from 'b'
	is pushed to 'a' to be adjacent with the last 'a' element */
int	top3last2_la_last(t_l *l, t_asc *asc, t_op *op, int bl_loc)
{
	t_p1	p1[1];

	p1->oddone = oddones(asc, bl_loc, l->la[l->ct_a - 1]);
	if (p1->oddone)
		return (0);
	p1->optype = PA;
	p1->bl_loc = bl_loc;
	p1->asc = asc;
	return (rotate_pa(l, op, p1));
}

/* if top a is not oddones, whatever push to a from b will add_bl to becomes
	not oddones, 
   if top a is oddones, top3last2 exist, first rotate to top b, then pb */
int	top3last2(t_l *l, t_asc *asc, t_op *op, int bl_loc)
{
	int		popval;
	t_p1	p1[1];

	p1->oddone = oddones(asc, bl_loc, l->la[0]);
	if (p1->oddone)
		p1->optype = PB;
	else
		p1->optype = PA;
	if (asc->ascend)
		popval = l->la[0] - 1;
	else
		popval = l->la[0] + 1;
	if (popval == -1)
		popval = l->ct_bk - 1;
	p1->bl_loc = bl_loc;
	p1->asc = asc;
	return (rotate_pa_pb(l, popval, op, p1));
}

/* top 'a' and last 'a' is in sequence,  so add top 'a' to bl */
int	la_last1_is_bl(t_l *l, t_asc *asc, int bl_loc)
{
	if ((!oddones(asc, bl_loc, l->la[l->ct_a - 1])) \
	&& (((asc->ascend) && ((l->la[0] - 1) == l->la[l->ct_a - 1])) \
	|| ((!asc->ascend) && ((l->la[0] + 1) == l->la[l->ct_a - 1]))))
	{
		if (oddones(asc, bl_loc, l->la[0]))
		{
			add_bl(asc, bl_loc, l->la[0]);
			return (1);
		}
	}
	return (0);
}

/* adjust the 1st element on stack 'a' be the least order value, do nothin if
	stack 'a' is empty or min element already at top 'a' */
void	least_order_top_a(t_l *l, t_op *op)
{
	int	min;
	int	max;
	int	ra_ct;
	int	rra_ct;

	arrloc_min_max(l, &min, &max);
	if ((min == -1) || (min == 0))
		return ;
	ra_ct = min;
	rra_ct = l->ct_a - min;
	if (ra_ct > rra_ct)
		exop(RRA, rra_ct, op, l);
	else
		exop(RA, ra_ct, op, l);
}

/* return 1 to continue next loop, 0 to quit looping, and 2 to continue next
	check and optimization of la and lb */
int	shuffle_la_lb_with_nearby_elements(t_l *l, t_asc *asc, t_op *op, int bl_loc)
{
	if (ordered_list(l))
	{
		least_order_top_a(l, op);
		return (0);
	}
	if ((asc->ct[bl_loc] + l->ct_b) == l->ct_bk)
		return (0);
	if (top3last2_la_last(l, asc, op, bl_loc))
	{
		return (1);
	}
	if (la_last1_is_bl(l, asc, bl_loc))
	{
		return (1);
	}
	if (top3last2(l, asc, op, bl_loc))
	{
		return (1);
	}
	return (2);
}
