/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker8_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:05:26 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/08 17:17:40 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
/*
void	p_op_list(char *oplist, int k)
{
	int		i;
	char	s[5];

	i = 0;
	ft_printf("\noperation list, total (%d)\n", k);
	while (i < k)
	{
		ft_printf("%4s",op_str(oplist[i], s));
		i++;
	}
}
*/

void	w_err(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

int	sa_sb_ss_pa_pb_ra_rb_rr(char *l, t_op *op)
{
	if ((l[0] == 's') && (l[1] == 'a'))
		op->op[op->opct] = SA;
	else if ((l[0] == 's') && (l[1] == 'b'))
		op->op[op->opct] = SB;
	else if ((l[0] == 's') && (l[1] == 's'))
		op->op[op->opct] = SS;
	else if ((l[0] == 'p') && (l[1] == 'a'))
		op->op[op->opct] = PA;
	else if ((l[0] == 'p') && (l[1] == 'b'))
		op->op[op->opct] = PB;
	else if ((l[0] == 'r') && (l[1] == 'a'))
		op->op[op->opct] = RA;
	else if ((l[0] == 'r') && (l[1] == 'b'))
		op->op[op->opct] = RB;
	else if ((l[0] == 'r') && (l[1] == 'r'))
		op->op[op->opct] = RR;
	else
		return (0);
	(op->opct)++;
	return (1);
}

int	rra_rrb_rrr(char *l, t_op *op)
{
	if ((l[0] == 'r') && (l[1] == 'r') && (l[2] == 'a'))
		op->op[op->opct] = RRA;
	else if ((l[0] == 'r') && (l[1] == 'r') && (l[2] == 'b'))
		op->op[op->opct] = RRB;
	else if ((l[0] == 'r') && (l[1] == 'r') && (l[2] == 'r'))
		op->op[op->opct] = RRR;
	else
		return (0);
	(op->opct)++;
	return (1);
}

/* instruction is either 3 or 4 char with terminating \n
	returns number of characters read counting the \n 
	read from stdin will terminate even when \n is not found at 4th char
	if less than 3 char can be read, meaning format error, l will not be updt
	if 3rd char is not \n, then read 1 more char
*/
int	read_instruction(char *l, int tot, char *b, int *ptr)
{
	static int	p;
	int			i;
	int			ret;

	if ((p + 3) <= tot)
	{
		ret = three_or_four_byte_instruction(l, b, p, tot);
		p += ret;
		*ptr = p;
		return (ret);
	}
	else
	{
		i = tot - p;
		p = tot;
		*ptr = p;
		return (i);
	}
}
