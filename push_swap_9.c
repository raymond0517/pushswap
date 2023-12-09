/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:43:30 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:44:22 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 3 elements or less then return 1 as avg is no longer representative */
int	la_avg(t_l *l, int from, int to)
{
	int	i;
	int	sum;

	if (from < 0)
		from = 0;
	if (to < 0)
		to = 0;
	if (from >= l->ct_a)
		from = l->ct_a - 1;
	if (to >= l->ct_a)
		to = l->ct_a - 1;
	i = from;
	sum = 0;
	while (i <= to)
	{
		sum += l->la[i];
		i++;
	}
	return (sum / (to - from + 1));
}

/* This function will return (1) if l->ct_a is <= 50, since <= 50, this
	filering is not required.
	i is arr loc l->la[i], the order value at la[i] is compare with 
	the average of next 6 order val (if available) and average of 
	previous 6 order val (if available),
	if (l->la[i]) within (0.1 * ct_a) of the average of either prev 6
	or next 6, then it returns (1) else it returns (0) */
int	within_avg(int i, t_l *l)
{
	int	leftavg;
	int	rightavg;
	int	from;
	int	to;
	int	val;

	if (l->ct_a <= 50)
		return (1);
	from = i - 6;
	to = i - 1;
	leftavg = la_avg(l, i - 6, i - 1);
	rightavg = la_avg(l, i + 1, i + 6);
	val = l->la[i];
	if (((val >= leftavg * 0.85) && (val <= leftavg * 1.15)) || \
	((val >= rightavg * 0.85) && (val <= rightavg * 1.15)))
		return (1);
	else
		return (0);
}

/* build loc[], updt nxt by scanning l->la from arr loc pointed by 
	loc[*nxt - 1], ascend flag is to determine whether ascending list
	or descending list when building loc[] list 	
	i = bl->st; // start arr loc in l->la
	val = bl->val; // val to compare with
			(*nxt)++; // next item will be added to higher arr location
			val = l->la[i]; // now will compare with the new value
*/
void	build_list(int *loc, int *nxt, t_l *l, t_bl *bl)
{
	int	i;
	int	val;

	i = bl->st;
	val = bl->val;
	while (i < l->ct_a)
	{
		if (((((bl->ascend) && (val < l->la[i])) || ((!(bl->ascend)) && \
		(val > l->la[i])))) && within_avg(i, l))
		{
			loc[*nxt] = i;
			(*nxt)++;
			val = l->la[i];
		}
		i++;
	}
}

/* ie. if last bl element is at arr loc 20 of la[], there exists some more 
	elements from la[20] to explore, will drop this last bl elements and 
	explore more ascending order elements */
void	more_elements_in_la_after_last_bl_element(int *nxt, \
t_bl *bl, t_l *l, int *loc)
{
	if ((*nxt) == 1)
	{
		loc[(*nxt) - 1]++;
		bl->st = loc[(*nxt) - 1];
		bl->val = l->la[bl->st];
	}
	else
	{
		(*nxt)--;
		bl->st = loc[(*nxt)] + 1;
		bl->val = l->la[loc[(*nxt) - 1]];
	}
}

/* note that bl->st keep on increasing, when nxt == 1, it means can no longer
	find more than 1 element in the build list, then search for ascending list
	will end, ie., return (1)
   if 3 or more buildlist elements, and list buildlist element is already the 
	last element in la[], then will give up last 2 buildlist elements,
	using the 3rd last element as compare value, start searching alternative 
	from 2nd last element + 1 onwards
   if only 2 elemnts in buildlist, will increase 2nd last buildlist element
	array location by 1, drop last buildlist element, start compare with 
	l->la[2nd last]

*/
int	no_more_element_in_la_after_last_bl_element(int *nxt, t_bl *bl, \
t_l *l, int *loc)
{
	if ((*nxt) >= 3)
	{
		bl->val = l->la[loc[(*nxt) - 3]];
		bl->st = loc[(*nxt) - 2] + 1;
		(*nxt) = (*nxt) - 2;
	}
	else if ((*nxt) == 2)
	{
		loc[0]++;
		(*nxt)--;
		bl->st = loc[0];
		bl->val = l->la[bl->st];
	}
	else if ((*nxt) == 1)
	{
		return (1);
	}
	return (0);
}
