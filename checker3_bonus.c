/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:55:53 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 02:57:24 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* min == -1 implies no element in la */
int	ordered_list(t_l *l)
{
	int	min;
	int	max;
	int	i;
	int	val;

	arrloc_min_max(l, &min, &max);
	if (min == -1)
		return (1);
	i = min;
	val = 0;
	while (val < l->ct_a)
	{
		if (val != l->la[i])
			return (0);
		val++;
		i++;
		if (i == l->ct_a)
			i = 0;
	}
	return (1);
}

void	sa(t_l *l)
{
	int	tmp;

	if (l->ct_a >= 2)
	{
		tmp = l->la[0];
		l->la[0] = l->la[1];
		l->la[1] = tmp;
	}
}

void	sb(t_l *l)
{
	int	tmp;

	if (l->ct_b >= 2)
	{
		tmp = l->lb[0];
		l->lb[0] = l->lb[1];
		l->lb[1] = tmp;
	}
}

/* if there are n elements, only 2nd to nth elements are shifted up 
   by 1 arr loc, 1st element is lost */
void	sh1up(char type, t_l *l)
{
	int	i;
	int	ct;

	i = 0;
	if (type == 'a')
		ct = l->ct_a;
	else
		ct = l->ct_b;
	while (i < ct - 1)
	{
		if (type == 'a')
			l->la[i] = l->la[i + 1];
		else
			l->lb[i] = l->lb[i + 1];
		i++;
	}
}

/* if there are n elements, all n elements are shifted down by 1 arr loc 
   all existing elements preserved */
void	sh1dn(char type, t_l *l)
{
	int	i;
	int	ct;

	if (type == 'a')
		ct = l->ct_a;
	else
		ct = l->ct_b;
	i = ct - 1;
	while (i >= 0)
	{
		if (type == 'a')
			l->la[i + 1] = l->la[i];
		else
			l->lb[i + 1] = l->lb[i];
		i--;
	}
}
