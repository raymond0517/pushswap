/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:35:06 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:35:57 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_l *l)
{
	int	tmp;

	if (l->ct_b >= 1)
	{
		tmp = l->lb[0];
		sh1up('b', l);
		(l->ct_b)--;
		sh1dn('a', l);
		l->la[0] = tmp;
		(l->ct_a)++;
	}
}

void	pb(t_l *l)
{
	int	tmp;

	if (l->ct_a >= 1)
	{
		tmp = l->la[0];
		sh1up('a', l);
		(l->ct_a)--;
		sh1dn('b', l);
		l->lb[0] = tmp;
		(l->ct_b)++;
	}
}

/* 1st element in 'a' becomes last element, the rest of elements in 'a' 
	shifted up by 1 array loc */
void	ra(t_l *l)
{
	int	tmp;

	if (l->ct_a > 1)
	{
		tmp = l->la[0];
		sh1up('a', l);
		l->la[l->ct_a - 1] = tmp;
	}
}

void	rb(t_l *l)
{
	int	tmp;

	if (l->ct_b > 1)
	{
		tmp = l->lb[0];
		sh1up('b', l);
		l->lb[l->ct_b - 1] = tmp;
	}
}

void	rra(t_l *l)
{
	int	tmp;

	if (l->ct_a > 1)
	{
		tmp = l->la[l->ct_a - 1];
		sh1dn('a', l);
		l->la[0] = tmp;
	}
}
