/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:44:45 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 05:02:16 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	int 	nxt; // next arr loc to use in loc[], it also tell
		//number of elements thus far in the buildlist
	int		loc[MAX_ASC]; // it stores arr loc of la[] with number 
			//in ascending order, pls note it is not storing l->la[i], 
			//but storing the value of index i
	loc[0] = 0; // pts to la[0]
	bl->st = loc[0]; // setting start loc means next item will be diff val 
					// start val and nxt tell total items currently in list

*/
void	search_asc(t_asc *asc, t_l *l)
{
	int		nxt;
	int		loc[MAX_ASC];
	t_bl	bl[1];
	int		ct;

	ct = 0;
	nxt = 1;
	loc[0] = 0;
	bl->st = loc[0];
	bl->val = l->la[loc[0]];
	bl->ascend = 1;
	while (1)
	{
		ct++;
		if (ct > MAX_BL_SEARCH)
			break ;
		build_list(loc, &nxt, l, bl);
		insert_ans(asc, loc, nxt, l);
		if (loc[nxt - 1] + 1 < l->ct_a)
			more_elements_in_la_after_last_bl_element(&nxt, bl, l, loc);
		else
			if (no_more_element_in_la_after_last_bl_element(&nxt, bl, l, loc))
				break ;
	}
}

int	longest_buildlist(t_asc *lst)
{
	int	i;
	int	max;
	int	ret;

	i = 0;
	max = 0;
	ret = -1;
	while (i < MAX_ANS)
	{
		if (lst->ct[i] > max)
		{
			max = lst->ct[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	oddones(t_asc *lst, int lstloc, int val)
{
	int	i;

	i = 0;
	while (i < lst->ct[lstloc])
	{
		if (val == lst->n[lstloc][i])
			return (0);
		i++;
	}
	return (1);
}

/*
	lastorder = -1; // when lst has all element in order, no odd ones, ret -1
*/
int	last_odd(t_asc *lst, int lstloc, t_l *l)
{
	int	i;
	int	lastorder;

	lastorder = -1;
	i = l->ct_a - 1;
	while (i >= 0)
	{
		if (oddones(lst, lstloc, l->la[i]))
		{
			lastorder = l->la[i];
			break ;
		}
		i--;
	}
	return (lastorder);
}

/* insloc assume to be appending after last element in bl->n[bl_loc][],
	if order_val is greater than all existing elements in bl->n[bl_loc][] */
int	ins_location(t_asc *bl, int bl_loc, int order_val)
{
	int	i;
	int	insloc;

	i = 0;
	insloc = bl->ct[bl_loc];
	while (i < bl->ct[bl_loc])
	{
		if (((bl->ascend) && (order_val < bl->n[bl_loc][i])) || \
		((!bl->ascend) && (order_val > bl->n[bl_loc][i])))
		{
			insloc = i;
			break ;
		}
		i++;
	}
	return (insloc);
}
