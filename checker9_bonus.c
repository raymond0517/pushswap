/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker9_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 03:07:26 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/08 17:20:55 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* check that it is either len 3 or 4 including \n, and that \n is in place 
	and that instruction set code is valid
	repeat reading a line ending with \n each time until eof or error encountered
 */
int	get_instructions(t_op *op)
{
	char	l[5];
	int		i;
	char	b[PIPE_DATA_MAX];
	int		tot;
	int		ptr;

	op->opct = 0;
	tot = 0;
	ptr = 0;
	while (1)
	{
		read_pipe_data(b, &tot, ptr);
		i = read_instruction(l, tot, b, &ptr);
		if (i == 0)
			return (1);
		if ((i != 3) && (i != 4))
			return (0);
		else if (((i == 3) && (l[2] != '\n')) || ((i == 4) && (l[3] != '\n')))
			return (0);
		else if (((i == 3) && (!sa_sb_ss_pa_pb_ra_rb_rr(l, op))) || \
		((i == 4) && (!rra_rrb_rrr(l, op))))
			return (0);
	}
}
/*
void	p_op(t_op *op)
{
	int		i;
	char	s[4];

	ft_printf("\nTotal instructions : %d\n", op->opct);
	i = 0;
	while (i < op->opct)
	{
		ft_printf("%4s", op_str(op->op[i], s));
		i++;
	}
}
*/

void	w_outcome(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
	write(1, "\n", 1);
}

int	sorted_list(t_l *l)
{
	int	i;

	i = 0;
	while (i < l->ct_a)
	{
		if (i != l->la[i])
			return (0);
		i++;
	}
	return (1);
}

void	validate_arg2_elements(char *s, t_sl *sl, t_l *l, int *error)
{
	int	val;

	if (validarg((s), sl))
	{
		val = atoi(s);
		ins_sort(val, sl);
		l->la[l->ct_a] = val;
		(l->ct_a)++;
	}
	else
		*error = 1;
}

void	validate(t_l *l, t_op *op)
{
	int		i;
	t_op	op2[1];

	i = 0;
	op2->opct = 0;
	while (i < op->opct)
	{
		exop(op->op[i], 1, op2, l);
		i++;
	}
	if (sorted_list(l) && (l->ct_b == 0))
		w_outcome("OK");
	else
		w_outcome("KO");
}
