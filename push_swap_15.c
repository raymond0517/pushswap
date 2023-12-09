/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_15.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:53:56 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:54:45 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_least_steps(t_act *action, t_op *op, t_l *l)
{
	exop(action[0].type, action[0].ct, op, l);
	exop(action[1].type, action[1].ct, op, l);
	exop(PA, 1, op, l);
}

/* l->la is dynamic, meaning, the ascending list can start at arr loc 4 and
	last highest order with arr loc at 3, it is circular, continue after 
	l->ct_a is arr loc 0, so first identify start arr loc with smaller order */

int	insloc_la(t_l *l, int insval)
{
	int	i;
	int	loc_smallest;
	int	loc_largest;

	if (l->ct_a == 0)
		return (0);
	arrloc_min_max(l, &loc_smallest, &loc_largest);
	i = loc_smallest;
	while (1)
	{
		if (insval < l->la[i])
			return (i);
		if (i == loc_largest)
			return (i + 1);
		i++;
		if (i == l->ct_a)
			i = 0;
	}
}

void	init_steps(t_act steps[][2])
{
	int	i;

	i = 0;
	while (i < A_SZ)
	{
		steps[i][0].ct = 0;
		steps[i][1].ct = 0;
		i++;
	}
}

/* returns the arr loc of steps[] that has the least total operations in
	(lb, la) */
int	least_steps_among_lb(t_act steps[][2], int ct_bk)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < ct_bk)
	{
		if (!((steps[i][0].ct == 0) && (steps[i][1].ct == 0)))
			if ((steps[ret][0].ct + steps[ret][1].ct) > \
			(steps[i][0].ct + steps[i][1].ct))
				ret = i;
		i++;
	}
	return (ret);
}

/* update operation counts in stp for further selection */
void	cal_cnt_for_diff_rotations(t_s *stp, t_l *l, int i)
{
	int	la_loc;

	la_loc = insloc_la(l, l->lb[i]);
	stp->ra_s = la_loc;
	if (la_loc == 0)
		stp->rra_s = 0;
	else
		stp->rra_s = l->ct_a - la_loc;
	stp->rb_s = i;
	if (i == 0)
		stp->rrb_s = 0;
	else
		stp->rrb_s = l->ct_b - i;
}
