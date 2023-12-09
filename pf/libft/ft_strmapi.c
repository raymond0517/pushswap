/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:26:59 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/19 20:31:11 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*r;

	len = 0;
	while (s[len])
		len++;
	r = (char *)malloc((sizeof(char)) * (len + 1));
	if (r != NULL)
	{
		len = 0;
		while (s[len])
		{
			r[len] = f(len, (char)s[len]);
			len++;
		}
		r[len] = '\0';
	}
	return (r);
}
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>

char	toupp(unsigned int i, char c)
{
	if (i > 10)
		if ((c >= 'a') && (c <= 'z'))
			return ((char)(c - 32));
	return (c);
}

void	pstrmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;

	r = ft_strmapi(s, f);
	if (r == NULL)
		printf("\nNULL ptr (%s)", strerror(errno));
	else
		printf("\norig (%s), ret (%s)", (char *)s, r);
}

int	main(void)
{
	pstrmapi("ABCDefghiJKLabcd", toupp);
	pstrmapi("", toupp);
	pstrmapi("Defg  $@@!^hiJKLabcd", toupp);
	pstrmapi("12345ABCDefghiJKLabcd", toupp);
	pstrmapi("ABCDe^$@!fghiJKLabcd", toupp);
	return (0);
} */
