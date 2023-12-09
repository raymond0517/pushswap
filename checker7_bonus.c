/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker7_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:04:01 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 03:18:31 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	get_order(int num, t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->ct)
	{
		if (num == sl->n[i])
			return (i);
		else
			i++;
	}
	return (-1);
}

void	updt_order(t_l *l, t_sl *sl)
{
	int	i;

	i = 0;
	while (i < l->ct_a)
	{
		l->la[i] = get_order(l->la[i], sl);
		l->bk[i] = l->la[i];
		i++;
	}
	l->ct_bk = l->ct_a;
}

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
