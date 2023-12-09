/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:47:13 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 00:38:34 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	ft_hexchr(int i, int uppercase)
{
	if ((i >= 0) && (i <= 9))
		return ((char)('0' + (char)i));
	else
	{
		if (uppercase)
			return ((char)('A' + (char)(i - 10)));
		else
			return ((char)('a' + (char)(i - 10)));
	}
}

void	ft_hexint(unsigned long in, char *r, int i, int upcase)
{
	if (in >= 16)
		ft_hexint(in / 16, r, i + 1, upcase);
	else
	{
		r[i] = ft_hexchr(in, upcase);
		r[i + 1] = '\0';
	}
	r[i] = ft_hexchr(in % 16, upcase);
}

void	ft_reverse(char *s)
{
	int		l;
	char	t;
	int		i;

	l = 0;
	while (s[l])
		l++;
	l--;
	i = 0;
	while (i < l)
	{
		t = s[i];
		s[i] = s[l];
		s[l] = t;
		i++;
		l--;
	}
}
