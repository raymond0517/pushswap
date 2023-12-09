/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_13.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:50:40 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:51:46 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*  la[0] is an odd one that can be pushed to stack 'b', 
	if la[0] can be swapped with la[1] to create an order list, swap it
	else push it to stack 'b'
	if ascend, eg. la[0] == 3, la[1] == 2
	if descent, eg. la[0] == 2, la[1] == 3 , then swap stack 'a'
	if 2nd top element already in buildlist, 
	then top element in stack 'a' also add to buildlist
 	if top stack 'a' element cannot be swapped with 2nd element
		push it as odd ones element into stack 'b'
	returns 0 if la[0] == lastodd element in la so that parent loop will end
 */
int	handle_first_la_element(t_l *l, t_asc *asc, t_op *op, t_p3 *p3)
{
	int	ret;

	ret = 1;
	if (((asc->ascend) && ((l->la[0] - 1) == l->la[1])) || \
	((!(asc->ascend)) && ((l->la[0] + 1) == l->la[1])))
	{
		if (!oddones(asc, p3->bl_loc, l->la[1]))
			add_bl(asc, p3->bl_loc, l->la[0]);
		exop(SA, 1, op, l);
	}
	else
	{
		exop(PB, 1, op, l);
	}
	return (ret);
}

/* RRR rotation type, count RRR steps needed from the nearest oddone to 
	ct_a to top 'a', 
	return -1 if oddones not found */
int	steps_to_oddone_rrr_rotation(t_asc *asc, int bl_loc, t_l *l)
{
	int	i;

	i = l->ct_a - 1;
	while (i >= 0)
	{
		if (oddones(asc, bl_loc, l->la[i]))
		{
			if (i == 0)
				return (0);
			return (l->ct_a - i);
		}
		i--;
	}
	return (-1);
}

/* either RR index from 0 increasing by 1 till l->ct_a - 1
	or RRR rotation type, index from l->ct_a - 1 till 0 */
int	steps_to_oddone(int rotate_type, t_asc *asc, int bl_loc, t_l *l)
{
	int	i;

	if (l->ct_a == 0)
		return (-1);
	i = 0;
	if (rotate_type == RR)
	{
		while (i < l->ct_a)
		{
			if (oddones(asc, bl_loc, l->la[i]))
				return (i);
			i++;
		}
	}
	else
	{
		return (steps_to_oddone_rrr_rotation(asc, bl_loc, l));
	}
	return (-1);
}

int	shortest_path_to_next_oddone(t_asc *asc, int bl_loc, t_l *l, t_op *op)
{
	int	rr_steps;
	int	rrr_steps;

	rr_steps = steps_to_oddone(RR, asc, bl_loc, l);
	rrr_steps = steps_to_oddone(RRR, asc, bl_loc, l);
	if (rr_steps == -1)
		return (0);
	if (rr_steps > rrr_steps)
	{
		exop(RRR, 1, op, l);
	}
	else
		exop(RR, 1, op, l);
	return (1);
}

/*
	if (!(top3last2(l, asc, op, bl_loc)))
	// stack 'a' untouched, so rotate 'rr' both stacks
		exop(RR, 1, op, l);

	top is not oddones, meaning top is in build list 
	will try to push any of the top 3 and last 2 elements 
	in stack 'b' to stack 'a' if orderval is 1 smaller than 
	element in top 'a' (for asc->ascend) or if orderval is 
	1 greater than top 'a' (for !asc->ascend)
	if any of the 'pa' is done, then add_bl for the orderval being
	pushed to stack 'a'
	lastly, rotate both lists
*/
void	oddones2stack_b(t_l *l, t_asc *asc, t_op *op, int bl_loc)
{
	t_p3	p3[1];
	int		loop;

	if (l->ct_a <= 1)
		return ;
	p3->last = last_odd(asc, bl_loc, l);
	p3->bl_loc = bl_loc;
	if (p3->last != -1)
	{
		loop = 1;
		while (loop)
		{
			loop = shuffle_la_lb_with_nearby_elements(l, asc, op, bl_loc);
			if (loop != 2)
				continue ;
			if (oddones(asc, bl_loc, l->la[0]))
				loop = handle_first_la_element(l, asc, op, p3);
			else
			{
				loop = shortest_path_to_next_oddone(asc, bl_loc, l, op);
			}
		}
	}
}
