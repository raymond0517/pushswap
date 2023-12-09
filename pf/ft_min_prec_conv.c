/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_prec_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:58:10 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 00:28:44 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* first search for conv character, while searching, make sure char in
   between are either '*', '.' or digits, if not these chars, flag error
	if error , returns ' ' else return conv char
*/
static char	get_conv_char(int *p, char const *f)
{
	while ((f[*p]) && (f[*p] != 'c') && (f[*p] != 's') && (f[*p] != 'p') && \
	(f[*p] != 'd') && (f[*p] != 'i') && (f[*p] != 'u') && (f[*p] != 'x') && \
	(f[*p] != 'X') && (f[*p] != '%'))
	{
		if ((f[*p] == '*') || (f[*p] == '.') || (ft_isdigit(f[*p])))
			(*p)++;
		else
			break ;
	}
	if ((f[*p] != 'c') && (f[*p] != 's') && (f[*p] != 'p') && \
	(f[*p] != 'd') && (f[*p] != 'i') && (f[*p] != 'u') && (f[*p] != 'x') && \
	(f[*p] != 'X') && (f[*p] != '%'))
		return (' ');
	return (f[*p]);
}

static int	ft_get_min_width(int i, char const *f)
{
	int	min;

	if (f[i] == '*')
		min = -1;
	else
	{
		if ((((char *)f)[i] >= '0') && \
		(((char *)f)[i] <= '9'))
			min = ft_atoi(&(f[i]));
		else
			min = 0;
	}
	return (min);
}

/* default prec when '.' exists with no precision is 0
	if '.' not exists, default precision is 1
*/
static int	ft_get_prec(int pos_dot, char const *f)
{
	int	prec;

	if (f[pos_dot + 1] == '*')
		prec = -1;
	else
	{
		if ((((char *)f)[pos_dot + 1] >= '0') && \
		(((char *)f)[pos_dot + 1] <= '9'))
			prec = ft_atoi(&(f[pos_dot + 1]));
		else
			prec = 0;
	}
	return (prec);
}

/* *i points to char after all flags in f, it
	returns min width, and precision, and 
	conversion char (this is done by the returned char 
	if no proper conv char found, it returns ' '
	if conv is 's', default precision cannot be 1,
		because it will truncate str to 1 char, hence,
		default set to INT_MAX
	get_conv_char fn changes p,
	if p > *i, implies min width or precision exists, as digits, or 
		'.' exists before conv char.
	In such a case, we will first search for existence of '.',
	if pos_dot < p means not pointing to conv char, implies '.' exists
		then get prec value
	will also get min width using *i position
	Note that if '*' wildcard detected for min width or prec
		min width or prec will be set to -1
	lastly, set *i to point to a char pass conv char 
				(f[p] points to conv char)
	fn ends with returning the conv char
*/
char	ft_min_prec_conv(int *i, int *min, int *prec, char const *f)
{
	int		p;
	int		pos_dot;
	char	conv;

	p = *i;
	conv = get_conv_char(&p, f);
	if (conv == ' ')
		return (conv);
	*prec = 1;
	if (conv == 's')
		*prec = INT_MAX;
	*min = 0;
	if (p > *i)
	{
		pos_dot = *i;
		while ((f[pos_dot] != '.') && (pos_dot != p))
			pos_dot++;
		if (pos_dot < p)
			*prec = ft_get_prec(pos_dot, f);
		*min = ft_get_min_width(*i, f);
	}
	*i = p + 1;
	return (conv);
}
