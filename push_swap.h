/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:22:18 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/07 19:55:15 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "pf/ft_printf.h"
# include "pf/libft/libft.h"
# define A_SZ 4000
# define MAX_ASC 4000
# define MAX_ANS 10
# define MAX_OP 60000
# define MAX_BL_SEARCH 30000
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

/* sorted list where arr loc (aka order) of inp num should be at */
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

typedef struct s_p3
{
	int	bl_loc;
	int	last;
}	t_p3;

/* used in rotate_pa_pb fn as 1 of the parameter, hence the name t_p1 */
typedef struct s_p1
{
	int		oddone;
	int		optype;
	int		bl_loc;
	t_asc	*asc;
}	t_p1;

/* used in fillgap fn as 1 of the parameter */
typedef struct s_p2
{
	int		st;
	int		end;
	int		loc;
	int		bl_loc;
}	t_p2;

/* ascend if = 1 would mean, build list of ascending number list else descending
	st used in build_list() to start compare value from an array loc of l->la 
	with val field */
typedef struct s_bl
{
	int	val;
	int	st;
	int	ascend;
}	t_bl;

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

/* struct to hold rra_s steps, ra_s steps, rrb_s steps, and rb_s steps 
	to help decide whether rrr or rr can be used to reduce total steps,
	need also to consider ascend in t_asc whether ascending or descending
	order in l->la */
typedef struct s_s
{
	int	ra_s;
	int	rra_s;
	int	rb_s;
	int	rrb_s;
}	t_s;

typedef struct s_pm
{
	int	pm[MAX_PERMUTATION][MAX_TOT_NUM];
	int	tot_num;
	int	last_permute_loc;
}	t_pm;

char	**ft_split(char const *s, char c);
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
void	op_str2(int type);
void	exop(int type, int repeat, t_op *op, t_l *l);
void	push_sl(int dst, int src, int cnt, t_sl *sl);
void	ins_sort(int val, t_sl *sl);
int		validarg(char *s, t_sl *sl);
int		get_order(int num, t_sl *sl);
void	updt_order(t_l *l, t_sl *sl);
void	ins_t_asc(t_asc *p, int *loc, t_l *l, int insloc);
void	insert_ans(t_asc *asc, int *loc, int nxt, t_l *l);
int		la_avg(t_l *l, int from, int to);
int		within_avg(int i, t_l *l);
void	build_list(int *loc, int *nxt, t_l *l, t_bl *bl);
void	more_elements_in_la_after_last_bl_element(int *nxt, \
t_bl *bl, t_l *l, int *loc);
int		no_more_element_in_la_after_last_bl_element(int *nxt, t_bl *bl, \
t_l *l, int *loc);
void	search_asc(t_asc *asc, t_l *l);
int		longest_buildlist(t_asc *lst);
int		oddones(t_asc *lst, int lstloc, int val);
int		last_odd(t_asc *lst, int lstloc, t_l *l);
int		ins_location(t_asc *bl, int bl_loc, int order_val);
void	add_bl(t_asc *bl, int bl_loc, int order_val);
int		rb_pa(int type, int rotate_ct, t_op *op, t_l *l);
int		rotate_pa_pb(t_l *l, int popval, t_op *op, t_p1 *p1);
void	execute_rotate_and_pa(t_l *l, t_op *op, t_p1 *p1, int v);
int		rotate_pa(t_l *l, t_op *op, t_p1 *p1);
int		top3last2_la_last(t_l *l, t_asc *asc, t_op *op, int bl_loc);
int		top3last2(t_l *l, t_asc *asc, t_op *op, int bl_loc);
int		la_last1_is_bl(t_l *l, t_asc *asc, int bl_loc);
void	least_order_top_a(t_l *l, t_op *op);
int		shuffle_la_lb_with_nearby_elements(t_l *l, t_asc *asc, \
t_op *op, int bl_loc);
int		handle_first_la_element(t_l *l, t_asc *asc, t_op *op, t_p3 *p3);
int		steps_to_oddone_rrr_rotation(t_asc *asc, int bl_loc, t_l *l);
int		steps_to_oddone(int rotate_type, t_asc *asc, int bl_loc, t_l *l);
int		shortest_path_to_next_oddone(t_asc *asc, int bl_loc, t_l *l, t_op *op);
void	oddones2stack_b(t_l *l, t_asc *asc, t_op *op, int bl_loc);
int		smallest(t_l *l);
int		arrloc(int *arr, int ct, int val);
void	cal_ra_rb(t_s *stp, t_act act[][2], int *tot);
void	cal_rra_rrb(t_s *stp, t_act act[][2], int *tot);
t_act	*least_steps(t_s *stp, t_act act[][2]);
void	exec_least_steps(t_act *action, t_op *op, t_l *l);
int		insloc_la(t_l *l, int insval);
void	init_steps(t_act steps[][2]);
int		least_steps_among_lb(t_act steps[][2], int ct_bk);
void	cal_cnt_for_diff_rotations(t_s *stp, t_l *l, int i);
void	ins_oddones_to_a(t_l *l, t_op *op);
void	cp_bk_to_la(t_l *l);
void	ins_oddones_to_descend_a(void);
int		least_tot_op(t_asc *asc);
void	cp_op_to_asc(t_asc *asc, t_op *op, int bl_loc);
int		first_last_swap_becomes_ordered_list(t_l *l, t_op *op);
int		further_processing_needed(t_l *l, t_op *op);
void	p_op_list(char *oplist, int k);
void	w_err(char *s);
void	validate_arg2_elements(char *s, t_sl *sl, t_l *l, int *error);
int		extract_args(char *s, t_sl *sl, t_l *l);
int		extract_argc(int argc, char *argv[], t_sl *sl, t_l *l);
void	sort_la(t_l *l, t_asc *asc, t_op *op);
void	generate_and_print_sorting_instructions(t_l *l, t_asc *asc, t_op *op);
#endif
