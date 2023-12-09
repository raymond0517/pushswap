/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:31:28 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:33:30 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_limit(long n, int negative, int *error)
{
	if (negative)
		n = (-1) * n;
	if ((n < MIN_INTEGER) || (n > MAX_INTEGER))
	{
		*error = 1;
		return (0);
	}
	return (1);
}

void	chk_int_format(char *s, int *error, int *negative)
{
	int	i;
	int	digit_exist;

	*negative = 0;
	if (s[0] == '-')
		*negative = 1;
	i = 0;
	digit_exist = 0;
	while ((s[i] != '\0') && (!(*error)))
	{
		if ((i == 0) && (!(((s[0] == '+') || (s[0] == '-')) || \
		((s[0] >= '0') && (s[0] <= '9')))))
			*error = 1;
		if ((s[i] >= '0') && (s[i] <= '9'))
			digit_exist = 1;
		if ((i > 0) && (!((s[i] >= '0') && (s[i] <= '9'))))
			*error = 1;
		i++;
	}
	if (!(digit_exist))
		*error = 1;
}

int	atoi_errdetect(char *s, int *error)
{
	int		negative;
	long	n;
	int		i;

	*error = 0;
	chk_int_format(s, error, &negative);
	if (*error)
		return (0);
	n = 0L;
	i = 0;
	while (s[i])
	{
		if (!((s[i] == '+') || (s[i] == '-')))
			n = (long)((*s) - '0') + (n * 10);
		if (!int_limit(n, negative, error))
			return (0);
		s++;
	}
	if (negative)
		n = (-1L) * n;
	return ((int) n);
}

void	init_var(t_l *l, t_sl *sl, t_asc *asc, t_op *op)
{
	int	i;

	l->ct_a = 0;
	l->ct_b = 0;
	l->ct_bk = 0;
	sl->ct = 0;
	i = 0;
	while (i < MAX_ANS)
	{
		asc->ct[i] = 0;
		i++;
	}
	op->opct = 0;
}

void	arrloc_min_max(t_l *l, int *min, int *max)
{
	int	i;

	if (l->ct_a == 0)
	{
		*min = -1;
		*max = -1;
	}
	i = 0;
	*min = 0;
	while (i < l->ct_a)
	{
		if (l->la[*min] > l->la[i])
			*min = i;
		i++;
	}
	*max = *min - 1;
	if (*min == 0)
		*max = l->ct_a - 1;
}
