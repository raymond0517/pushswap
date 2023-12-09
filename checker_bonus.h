/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:22:18 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/08 17:27:48 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include "pf/ft_printf.h"
# include "pf/libft/libft.h"
# define A_SZ 4000
# define MAX_ASC 4000
# define MAX_ANS 10
# define MAX_OP 60000
# define MAX_BL_SEARCH 30000
# define PIPE_DATA_MAX 40000
# define MAX_PERMUTATION 6000
# define MAX_TOT_NUM 7
# define MAX_INTEGER 2147483647
# define MIN_INTEGER -2147483648
# define GREEN "\033[32m"
# define DEFAULT "\033[0m"
# define SA 0
# define SB 1
# define PA 2
# define PB 3
# define RA 4
# define RB 5
# define RR 6
# define SS 7
# define RRA 8
# define RRB 9
# define RRR 10
# define OP_STR "SA SB PA PB RA RB RR SS RRARRBRRR"

/* bk is meant to keep a backup of input order as la[] will be a working set
	to be messed up when operations act upon the la[] and lb[[].
   first method, will use la and lb to generate instruction sets
	it will have a total count of instructions
   if 2nd method is to be applied, bk[] will restore la[] to its initial state,

	while lb[] empty, then 2nd method is to apply, another instructions to be
	generated, then compare the total count of instructions, 
   the smaller instructions set will be selected as solution.
*/
typedef struct s_l
{
	int	la[A_SZ];
	int	lb[A_SZ];
	int	bk[A_SZ];
	int	ct_a;
	int	ct_b;
	int	ct_bk;
}	t_l;

/* sorted list where arr loc (aka order) of inp num 
should be at is in this list */
typedef struct s_sl
{
	int	n[A_SZ];
	int	ct;
}	t_sl;

/* n[][] stores the order value of l->la[i], which l->la[i] gives the order
	of the inp number, the order in l->l/a[i] should be in ascending
	or descending order depending on the nature of the build list, the order
	is determined by ascend variable. if ascend == 1 then it is ascending order
*/
typedef struct s_asc
{
	int		n[MAX_ANS][MAX_ASC];
	int		ct[MAX_ANS];
	int		tot_op[MAX_ANS];
	char	op[MAX_ANS][MAX_OP];
	int		ascend;
}	t_asc;

typedef struct s_op
{
	char	op[MAX_OP];
	int		opct;
}	t_op;

/* type refers to SA, SB, PA, PB, RA, RB, RRA, RRB, SS, RR, RRR
	ct refers to repeat action on the above type for ct times */
typedef struct s_act
{
	int	type;
	int	ct;
}	t_act;

int		int_limit(long n, int negative, int *error);
void	chk_int_format(char *s, int *error, int *negative);
int		atoi_errdetect(char *s, int *error);
void	init_var(t_l *l, t_sl *sl, t_asc *asc, t_op *op);
void	arrloc_min_max(t_l *l, int *min, int *max);
int		ordered_list(t_l *l);
void	sa(t_l *l);
void	sb(t_l *l);
void	sh1up(char type, t_l *l);
void	sh1dn(char type, t_l *l);
void	pa(t_l *l);
void	pb(t_l *l);
void	ra(t_l *l);
void	rb(t_l *l);
void	rra(t_l *l);
void	rrb(t_l *l);
void	rr(t_l *l);
void	ss(t_l *l);
void	rrr(t_l *l);
void	log_op(int type, t_op *op);
void	exrotate(int type, t_l *l);
void	exop(int type, int repeat, t_op *op, t_l *l);
void	push_sl(int dst, int src, int cnt, t_sl *sl);
void	ins_sort(int val, t_sl *sl);
int		validarg(char *s, t_sl *sl);
int		get_order(int num, t_sl *sl);
void	updt_order(t_l *l, t_sl *sl);
int		smallest(t_l *l);
int		arrloc(int *arr, int ct, int val);
void	init_steps(t_act steps[][2]);
void	cp_bk_to_la(t_l *l);
void	w_err(char *s);
int		sa_sb_ss_pa_pb_ra_rb_rr(char *l, t_op *op);
int		rra_rrb_rrr(char *l, t_op *op);
int		read_instruction(char *l, int tot, char *b, int *ptr);
int		get_instructions(t_op *op);
void	w_outcome(char *s);
int		sorted_list(t_l *l);
void	validate_arg2_elements(char *s, t_sl *sl, t_l *l, int *error);
void	validate(t_l *l, t_op *op);
int		extract_args(char *s, t_sl *sl, t_l *l);
int		extract_argc(int argc, char *argv[], t_sl *sl, t_l *l);
void	read_pipe_data(char *b, int *tot, int ptr);
int		three_or_four_byte_instruction(char *l, char *b, int p, int tot);
#endif
