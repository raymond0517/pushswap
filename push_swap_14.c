/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_14.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:52:12 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:53:32 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* return -1 if no element in l->lb[]
	else return the array location of l->lb[] with lowest order number */
int	smallest(t_l *l)
{
	int	i;
	int	loc;

	if (l->ct_b == 0)
		return (-1);
	i = 0;
	loc = 0;
	while (i < l->ct_b)
	{
		if (l->lb[i] < l->lb[loc])
		{
			loc = i;
		}
		i++;
	}
	return (loc);
}

/* given an array, search for arr loc with content == val, returns arr loc 
	if not found return -1 */
int	arrloc(int *arr, int ct, int val)
{
	int	i;

	i = 0;
	while (i < ct)
	{
		if (arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

/* if ra cnt >= rb cnt , 
		 rr (stp->rb_s) times and ra (stp->ra_s - stp->rb_s) times
   else
		 rr (stp->ra_s) times and rb (stp->rb_s - stp->ra_s) times
*/
void	cal_ra_rb(t_s *stp, t_act act[][2], int *tot)
{
	if (stp->ra_s >= stp->rb_s)
	{
		tot[0] = (stp->ra_s);
		act[0][0].type = RR;
		act[0][0].ct = stp->rb_s;
		act[0][1].type = RA;
		act[0][1].ct = (stp->ra_s - stp->rb_s);
	}
	else
	{
		tot[0] = (stp->rb_s);
		act[0][0].type = RR;
		act[0][0].ct = stp->ra_s;
		act[0][1].type = RB;
		act[0][1].ct = (stp->rb_s - stp->ra_s);
	}
}

void	cal_rra_rrb(t_s *stp, t_act act[][2], int *tot)
{
	if (stp->rra_s >= stp->rrb_s)
	{
		act[1][0].type = RRR;
		act[1][0].ct = stp->rrb_s;
		act[1][1].type = RRA;
		act[1][1].ct = (stp->rra_s - stp->rrb_s);
		tot[1] = (stp->rra_s);
	}
	else
	{
		act[1][0].type = RRR;
		act[1][0].ct = stp->rra_s;
		act[1][1].type = RRB;
		act[1][1].ct = (stp->rrb_s - stp->rra_s);
		tot[1] = (stp->rrb_s);
	}
}

/*	
examine la, identify the largest number(l), fill up hole larger than l 
from lb[], then, search for holes less than l, 
for each hole, it can be a range of numbers or just 1 number.

start filling the smaller number to the larger number in the hole
	starts from l->la[l->ct_a - 1] to (ct_bk - 1)
	identify range of gap (start, end)
	l->la[i] reduced i-- 
	cmp l->la[i] with l->la[i + 1]
	if not consecutive, there is gap
	repeat until l->la[0] and compare with 0, aim to identfy gap in reducing
		order value
	for each gap
		look for l->lb[i] for the order value
		use i to decide rrb or rb and num of times
		also rra or ra num of times to have largest gap value + 1 at top 'a'
		then pa largest gap value to smallest gap value
*/

/* 4 approaches, (0) rr then ra or rb, (1) rrr then rra or rrb,
	first 2 approaches will utilize rr and rrr to save operations.
	whereas	(2) ra and rrb (3) rra and rb will operate separately, 
	we calculate each approach, then
	choose the least operations to acheive the same result.
	return ptr to struct containing the 2 operations with least total count */
t_act	*least_steps(t_s *stp, t_act act[][2])
{
	int	tot[4];
	int	i;
	int	ret;

	cal_ra_rb(stp, act, tot);
	cal_rra_rrb(stp, act, tot);
	act[2][0].type = RA;
	act[2][0].ct = stp->ra_s;
	act[2][1].type = RRB;
	act[2][1].ct = (stp->rrb_s);
	tot[2] = (stp->ra_s + stp->rrb_s);
	act[3][0].type = RRA;
	act[3][0].ct = stp->rra_s;
	act[3][1].type = RB;
	act[3][1].ct = (stp->rb_s);
	tot[3] = (stp->rra_s + stp->rb_s);
	i = -1;
	ret = 0;
	while ((++i) < 4)
		if (tot[ret] > tot[i])
			ret = i;
	return (act[ret]);
}
