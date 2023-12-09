/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_print_1_conv.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 23:31:03 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 19:14:19 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_push_in_flag(char *flag, char conv)
{
	int	i;

	i = 0;
	while (flag[i])
		i++;
	flag[i] = conv;
	flag[i + 1] = '\0';
}

static int	ft_find_dot(char const *f, int i)
{
	while ((f[i]) && (f[i] != 'c') && (f[i] != 's') && (f[i] != 'p') && \
	(f[i] != 'd') && (f[i] != 'i') && (f[i] != 'u') && \
	(f[i] != 'x') && (f[i] != 'X') && (f[i] != '%'))
	{
		if (f[i] == '.')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* f points at 1 char after '%' 
	flag will contains all possible flags up to max 4 '-','+','#','0',' '
	also will append '.' to indicate that a precision exists.
*/
static int	ft_get_flags(char *flag, char const *f)
{
	int	i;

	i = 0;
	while ((f[i]) && ((f[i] == '-') || (f[i] == '+') || (f[i] == '#') \
	|| (f[i] == '0') || (f[i] == ' ')))
	{
		flag[i] = (char)f[i];
		i++;
		if (i >= 5)
			return (-1);
	}
	flag[i] = '\0';
	if (ft_find_dot(f, i))
	{
		flag[i] = '.';
		flag[i + 1] = '\0';
	}
	return (i);
}

static void	ft_read_min_prec_arg(int *min, int *prec, va_list args)
{
	if (*min == -1)
		*min = va_arg(args, int);
	if (*prec == -1)
		*prec = va_arg(args, int);
}

/* function processing all flags, min width, and maximum (or precision) width, 
   read argument min width, precision width (if wildcard), and variable content 
   to be converted, and print it in the right format
	flag[7], size 7 because consider max num of flag to be 4, plus conv char
		being pushed to the end of flag[] due to limit of maximum 4 args per
		function call set by 42 std.
	ft_get_flags will update flag with all flags detected
	and that i will point to a char past all flags. 
	flag contains all flag char, if it contains all 5 flags, treated as error
	not valid to hv all 5 flags at the same time, 
	after ft_min_prec_conv function call,
	i now points to 1st char past all flags, means either start of 
	min width or '.' or conv char
	if conv char returned is ' ',  
		it means invalid min width or precision format
		or invalid conv char, hence, error

*/

int	ft_extract_print_1_conv(char const *f, va_list args, int *pcnt)
{
	char	flag[7];
	int		min;
	int		prec;
	char	conv;
	int		i;

	i = ft_get_flags(flag, f);
	if (i == -1)
		return (0);
	conv = ft_min_prec_conv(&i, &min, &prec, f);
	if (conv == ' ')
		return (0);
	else
	{
		ft_read_min_prec_arg(&min, &prec, args);
		ft_push_in_flag(flag, conv);
		if ((conv == '%') || (conv == 'c') || (conv == 'p'))
			*pcnt += ft_p_conv_percent_c_p(flag, min, args);
		else if ((conv == 's') || (conv == 'x') || (conv == 'X'))
			*pcnt += ft_p_conv_s_x_upp_x(flag, min, prec, args);
		else if ((conv == 'i') || (conv == 'd') || (conv == 'u'))
			*pcnt += ft_p_conv_i_d_u(flag, min, prec, args);
	}
	return (i);
}
