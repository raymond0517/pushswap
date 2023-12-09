/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker4_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 02:59:02 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 03:00:30 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* 1st element in 'b' pop out, remaining element in 'b' move upward 
	by 1 location and push into 1st element in 'a', existing elements in 
	'a' pushed down, 'a' increased 1 element, 'b' decrease 1 element */
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
