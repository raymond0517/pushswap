/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:59:07 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 17:35:00 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/*
void	p_ans(t_asc *asc, t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAX_ANS)
	{
		if (asc->ct[i])
		{
			ft_printf("(bl %d) ", i);
			j = 0;
			while (j < asc->ct[i])
			{
				ft_printf("%i(%s%i,%i%s) ", j, GREEN, \
				asc->n[i][j], sl->n[asc->n[i][j]], DEFAULT);
				j++;
			}
			ft_printf("\n");
		}
		i++;
	}
}

void	p_bl(t_asc *bl, int bl_loc)
{
	int	i;

	i = 0;
	ft_printf("\nbl[%d]: ", bl_loc);
	while (i < bl->ct[bl_loc])
	{
		ft_printf("%4d", bl->n[bl_loc][i]);
		i++;
	}
}

void	p_all_bl(t_asc *bl)
{
	int	i;

	i = 0;
	while (i < MAX_ANS)
	{
		p_bl(bl, i);
		i++;
	}
}

void	p_counts(t_asc *asc, t_l *l, int bl_loc)
{
	ft_printf("\nbl tot (%d), lb tot (%d)\n", asc->ct[bl_loc], l->ct_b);
}

void	p_a(t_l *l, t_sl *sl)
{
	int		i;

	i = 0;
	ft_printf("\nStack 'a' (num, order) : \n");
	while (i < l->ct_a)
	{
		ft_printf("%i(%s%i, %i%s)", i, GREEN, sl->n[l->la[i]], l->la[i], DEFAULT);
		i++;
	}
	i = -1;
	ft_printf("\n%s      ", GREEN);
	while (++i < l->ct_a)
		ft_printf("%3i ", i);

	i = -1;
	ft_printf("\n%sNum   ", GREEN);
	while (++i < l->ct_a)
		ft_printf("%3i ", sl->n[l->la[i]]);
	i = -1;
	ft_printf(  "\nOrder ");
	while (++i < l->ct_a)
		ft_printf("%3i ", l->la[i]);
	ft_printf("\n");
}

void	p_both_order(t_l *l)
{
	int		i;
	int		pnum;

	i = 0;
	ft_printf("\nStack 'a' : \n");
	while (i < l->ct_a)
	{
		pnum = l->la[i];
		ft_printf("%i(%s%i%s)", i, GREEN, pnum, DEFAULT);
		i++;
	}
	ft_printf("\n");
	i = 0;
	ft_printf("\nStack 'b' : \n");
	while (i < l->ct_b)
	{
		pnum = l->lb[i];
		ft_printf("%i(%s%i%s)", i, GREEN, pnum, DEFAULT);
		i++;
	}
	ft_printf("\n");
}

void	p_input(t_l *l, t_sl *sl)
{
	int		i;
	int		pnum;

	i = 0;
	ft_printf("\nInput number list : \n");
	while (i < l->ct_bk)
	{
		pnum = sl->n[l->bk[i]];
		ft_printf("(%s%i%s)", GREEN, pnum, DEFAULT);
		i++;
	}
}

void	p_both(t_l *l, t_sl *sl, int order)
{
	int		i;
	int		pnum;

	i = 0;
	ft_printf("\nStack 'a' : \n");
	while (i < l->ct_a)
	{
		pnum = l->la[i];
		if (!order)
			pnum = sl->n[l->la[i]];
		ft_printf("%i(%s%i%s)", i, GREEN, pnum, DEFAULT);
		i++;
	}
	i = 0;
	ft_printf("\n\nStack 'b' : \n");
	while (i < l->ct_b)
	{
		pnum = l->lb[i];
		if (!order)
			pnum = sl->n[l->lb[i]];
		ft_printf("%i(%s%i%s)", i, GREEN, pnum, DEFAULT);
		i++;
	}
}

void	p_la(t_l *l)
{
	int	i;

	i = 0;
	ft_printf("\nla content: ");
	while (i < l->ct_a)
	{
		ft_printf("%i(%s%i%s)", i, GREEN, l->la[i], DEFAULT);
		i++;
	}
	ft_printf("\n");
}

void	p_all(t_asc *bl, t_l *l,  int bl_loc)
{
	p_counts(bl, l, bl_loc);
	p_bl(bl, bl_loc);
	p_both_order(l);
	getchar();
}
*/
int	extract_args(char *s, t_sl *sl, t_l *l)
{
	char	**args;
	size_t	i;
	int		error;

	args = ft_split(s, ' ');
	if (args != NULL)
	{
		i = 0;
		error = 0;
		while (args[i] != NULL)
		{
			if (!error)
				validate_arg2_elements(args[i], sl, l, &error);
			free(args[i]);
			i++;
		}
		free(args[i]);
		free(args);
		if (error)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	extract_argc(int argc, char *argv[], t_sl *sl, t_l *l)
{
	int		val;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (validarg((argv[i]), sl))
		{
			val = atoi(argv[i]);
			ins_sort(val, sl);
			l->la[l->ct_a] = val;
			(l->ct_a)++;
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_sl	sl[1];
	t_l		l[1];
	t_asc	asc[1];
	t_op	op[1];

	init_var(l, sl, asc, op);
	if (argc == 1)
		return (0);
	if (((argc == 2) && (!extract_args(argv[1], sl, l))) || \
	((argc > 2) && (!extract_argc(argc, argv, sl, l))))
	{
		w_err("Error\n");
		return (255);
	}
	updt_order(l, sl);
	if (!get_instructions(op))
	{
		w_err("Error\n");
		return (255);
	}
	else
		validate(l, op);
	return (0);
}
