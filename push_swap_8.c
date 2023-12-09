/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:41:51 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:42:49 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validarg(char *s, t_sl *sl)
{
	int	i;
	int	num;
	int	error;

	num = atoi_errdetect(s, &error);
	if (error)
	{
		return (0);
	}
	i = 0;
	while (i < sl->ct)
	{
		if (num == sl->n[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

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

void	ins_t_asc(t_asc *p, int *loc, t_l *l, int insloc)
{
	int	i;

	i = 0;
	while (i < p->ct[insloc])
	{
		p->n[insloc][i] = l->la[loc[i]];
		i++;
	}
}

void	insert_ans(t_asc *asc, int *loc, int nxt, t_l *l)
{
	int	i;
	int	insloc;

	i = -1;
	insloc = -1;
	while ((++i) < MAX_ANS)
		if (asc->ct[i] == 0)
			break ;
	if (i == MAX_ANS)
	{
		i = -1;
		while ((++i) < MAX_ANS)
		{
			if (asc->ct[i] < nxt)
				insloc = i;
		}
	}
	else
		insloc = i;
	if (insloc != -1)
	{
		asc->ct[insloc] = nxt;
		ins_t_asc(asc, loc, l, insloc);
	}
}
