/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:12:15 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/15 02:20:22 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_null_str(int prec, char *null)
{
	if (prec >= 6)
		ft_strlcpy(null, "(null)", 7);
	else
		ft_strlcpy(null, "", 7);
}

/* flag now has conv type info, becuase 42 max 4 arguments in function limit */
int	ft_p_conv_s_x_upp_x(char *flag, int min, int prec, va_list args)
{
	char	*str;
	char	hex[17];
	char	null[7];

	if (ft_strchr(flag, 's'))
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_set_null_str(prec, null);
			return (ft_p_str(flag, min, prec, null));
		}
		else
			return (ft_p_str(flag, min, prec, str));
	}
	else
	{
		if (ft_strchr(flag, 'X'))
			ft_hexint(va_arg(args, unsigned int), hex, 0, 1);
		else
			ft_hexint(va_arg(args, unsigned int), hex, 0, 0);
		ft_reverse(hex);
		return (ft_p_hex(flag, min, prec, hex));
	}
}

int	ft_p_conv_percent_c_p(char *flag, int min, va_list args)
{
	char			c[2];
	unsigned long	ul;
	char			hex[17];

	if (ft_strchr(flag, '%'))
	{
		c[0] = '%';
		c[1] = '\0';
		ft_putstr_fd(c, 1);
		return (1);
	}
	else if (ft_strchr(flag, 'c'))
	{
		c[0] = (char)va_arg(args, int);
		c[1] = '\0';
		return (ft_p_chr(flag, min, c));
	}
	else
	{
		ul = va_arg(args, unsigned long);
		ft_hexint(ul, hex, 0, 0);
		ft_reverse(hex);
		return (ft_p_ptr(flag, min, hex));
	}
}

/* flag is pushed with conv char 'i', 'd', 'u' */
int	ft_p_conv_i_d_u(char *flag, int min, int prec, va_list args)
{
	unsigned int	ui;
	char			*str;
	int				ret;

	if (ft_strchr(flag, 'u'))
	{
		ui = va_arg(args, unsigned int);
		str = ft_utoa(ui);
		ret = (ft_p_unsigned(flag, min, prec, str));
		free(str);
	}
	else
	{
		str = ft_itoa(va_arg(args, int));
		ret = (ft_p_int(flag, min, prec, str));
		free(str);
	}
	return (ret);
}
