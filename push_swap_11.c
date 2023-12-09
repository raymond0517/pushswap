/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_11.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:46:35 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:47:40 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* add new element to bl, the val should be inserted after the element with 
	value (val - 1)
	if (insloc < bl->ct[bl_loc]) // to shift existing members down the list
*/
void	add_bl(t_asc *bl, int bl_loc, int order_val)
{
	int	i;
	int	insloc;

	insloc = ins_location(bl, bl_loc, order_val);
	if (insloc < bl->ct[bl_loc])
	{
		i = bl->ct[bl_loc];
		while (i - 1 >= insloc)
		{
			bl->n[bl_loc][i] = bl->n[bl_loc][i - 1];
			i--;
		}
	}
	bl->n[bl_loc][insloc] = order_val;
	(bl->ct[bl_loc])++;
}

int	rb_pa(int type, int rotate_ct, t_op *op, t_l *l)
{
	exop(type, rotate_ct, op, l);
	exop(PA, 1, op, l);
	return (1);
}

/*
if (!(p1->oddone)) // sequence is important, only after PA, add_bl with la[0]
*/
int	rotate_pa_pb(t_l *l, int popval, t_op *op, t_p1 *p1)
{
	if (((l->ct_b > 0) && (l->lb[0] == popval)) || \
	((l->ct_b > 1) && (l->lb[1] == popval)) || \
	((l->ct_b > 2) && (l->lb[2] == popval)) || \
	((l->ct_b > 3) && (l->lb[l->ct_b - 1] == popval)) || \
	((l->ct_b > 4) && (l->lb[l->ct_b - 2] == popval)))
	{
		if ((l->ct_b > 1) && (l->lb[1] == popval))
			exop(RB, 1, op, l);
		else if ((l->ct_b > 2) && (l->lb[2] == popval))
			exop(RB, 2, op, l);
		else if ((l->ct_b > 3) && (l->lb[l->ct_b - 1] == popval))
			exop(RRB, 1, op, l);
		else if ((l->ct_b > 4) && (l->lb[l->ct_b - 2] == popval))
			exop(RRB, 2, op, l);
		exop(p1->optype, 1, op, l);
		if (!(p1->oddone))
			add_bl(p1->asc, p1->bl_loc, l->la[0]);
		return (1);
	}
	else
		return (0);
}

void	execute_rotate_and_pa(t_l *l, t_op *op, t_p1 *p1, int v)
{
	if ((l->ct_b > 1) && ((l->lb[1] == v + 1) || (l->lb[1] == v - 1)))
		exop(RB, 1, op, l);
	else if ((l->ct_b > 2) && ((l->lb[2] == v + 1) || (l->lb[2] == v - 1)))
		exop(RB, 2, op, l);
	else if ((l->ct_b > 3) && ((l->lb[l->ct_b - 1] == v + 1) || \
	(l->lb[l->ct_b - 1] == v - 1)))
		exop(RRB, 1, op, l);
	else if ((l->ct_b > 4) && ((l->lb[l->ct_b - 2] == v + 1) || \
	(l->lb[l->ct_b - 2] == v - 1)))
		exop(RRB, 2, op, l);
	if (((p1->asc->ascend) && (l->lb[0] == v - 1)) || \
	((!(p1->asc->ascend)) && (l->lb[0] == v + 1)))
		exop(RRA, 1, op, l);
	exop(p1->optype, 1, op, l);
}

/* if 2nd top 'b' element diff from last 'a' by 1, RB, 3rd top 'b' element
	diff last 'a' by 1, RB twice, if last element in 'b' diff from last 'a' 
	by 1, RRB, if 2nd last element in 'b' diff from last 'a' by 1, RRB twice
	Now, element in 'b' of interest is at top 'b', 
	depends on buildlist is ascending or descending order, RRA the last 'a'
	element to top 'a' if needed in order that after pushing top 'b' to 
	top 'a', the 2 elements are in correct order, finally, if element from 
	top 'b' pushed to top 'a' is oddone element, then add the element to build
	list 
	returns 1 if there is element from 'b' pushed to 'a' else return 0 */
int	rotate_pa(t_l *l, t_op *op, t_p1 *p1)
{
	int	v;

	v = l->la[l->ct_a - 1];
	if (((l->ct_b > 0) && ((l->lb[0] == (v + 1)) || (l->lb[0] == (v - 1)))) \
	|| ((l->ct_b > 1) && ((l->lb[1] == v + 1) || (l->lb[1] == v - 1))) || \
	((l->ct_b > 2) && ((l->lb[2] == v + 1) || (l->lb[2] == v - 1))) || \
	((l->ct_b > 3) && ((l->lb[l->ct_b - 1] == v + 1) || \
	(l->lb[l->ct_b - 1] == v - 1))) || \
	((l->ct_b > 4) && ((l->lb[l->ct_b - 2] == v + 1) || \
	(l->lb[l->ct_b - 2] == v - 1))))
	{
		execute_rotate_and_pa(l, op, p1, v);
		if (oddones(p1->asc, p1->bl_loc, l->la[0]))
			add_bl(p1->asc, p1->bl_loc, l->la[0]);
		return (1);
	}
	else
		return (0);
}
