/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:36:18 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:37:32 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_l *l)
{
	int	tmp;

	if (l->ct_b > 1)
	{
		tmp = l->lb[l->ct_b - 1];
		sh1dn('b', l);
		l->lb[0] = tmp;
	}
}

void	rr(t_l *l)
{
	ra(l);
	rb(l);
}

void	ss(t_l *l)
{
	sa(l);
	sb(l);
}

void	rrr(t_l *l)
{
	rra(l);
	rrb(l);
}

void	log_op(int type, t_op *op)
{
	op->op[op->opct] = type;
	(op->opct)++;
}
