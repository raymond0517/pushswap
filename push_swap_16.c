/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:56:17 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:57:11 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* l->la[] is dynamic, because of PA, and RA, RRA, RR, RRR,
	so la[] is a circular ascending list of order numbers
	e.g. la[4] can be the smallest order number, la[5] is larger order
	keep increasing to la[ct_a - 1] then continue to increase in order num
	at la[0], the largest will be la[3]. 
	first loop loop till l->ct_b == 0,
		however, will examine all elements (another subloop) in l->lb[] 
		to keep a count number of operations needed to add to l->la 
		in ascending order.
		and at the end of it, choose the element in lb with least operations  
		be inserted to la[], need to take note of current top 'a'
		and the use of rra and ra count, and rrb and rb count, identify the use of 
		rrr or rr where possible to reduce the num of operations.
	every PA operation, will reduced ct_b by 1.
*/
void	ins_oddones_to_a(t_l *l, t_op *op)
{
	int		i;
	t_s		stp[1];
	t_act	act[4][2];
	t_act	steps[A_SZ][2];
	t_act	*chosen_act;

	while (l->ct_b > 0)
	{
		i = 0;
		init_steps(steps);
		while (i < l->ct_b)
		{
			cal_cnt_for_diff_rotations(stp, l, i);
			chosen_act = least_steps(stp, act);
			steps[i][0].type = chosen_act[0].type;
			steps[i][0].ct = chosen_act[0].ct;
			steps[i][1].type = chosen_act[1].type;
			steps[i][1].ct = chosen_act[1].ct;
			i++;
		}
		i = least_steps_among_lb(steps, l->ct_bk);
		exec_least_steps(steps[i], op, l);
	}
}

void	cp_bk_to_la(t_l *l)
{
	int	i;

	i = 0;
	while (i < l->ct_bk)
	{
		l->la[i] = l->bk[i];
		i++;
	}
	l->ct_a = l->ct_bk;
	l->ct_b = 0;
}

void	ins_oddones_to_descend_a(void)
{
}

/* return arr loc to (t_asc)->tot_op with the least total operation count */
int	least_tot_op(t_asc *asc)
{
	int	i;
	int	loc;

	i = -1;
	loc = 0;
	while ((++i) < MAX_ANS)
	{
		if (asc->tot_op[loc] > asc->tot_op[i])
			loc = i;
	}
	return (loc);
}

void	cp_op_to_asc(t_asc *asc, t_op *op, int bl_loc)
{
	int	i;

	asc->tot_op[bl_loc] = op->opct;
	i = 0;
	while (i < op->opct)
	{
		asc->op[bl_loc][i] = op->op[i];
		i++;
	}
}
