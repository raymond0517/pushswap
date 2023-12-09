/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:36:02 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/20 03:11:46 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if ((!(*s)) || (f == NULL))
		return ;
	i = 0;
	while (s[i])
	{
		f(i, (char *)(s + i));
		i++;
	}
}

void	reverse_case(unsigned int i, char *c)
{
	if ((i > 10) && (*c >= 'a') && (*c <= 'z'))
		*c = (*c) - 32;
	else if ((i <= 10) && (*c >= 'A') && (*c <= 'Z'))
		*c = (*c) + 32;
}
/*
#include <string.h>
#include <stdio.h>

void	p_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	str[100];

	strcpy(str, s);
	printf("\nBef (%s), fn is (%s)", s, ((f == NULL) ? "NULL": "not NULL"));
	ft_striteri(str, f);
	printf("\nAft (%s)", str);
	printf("\n---------");
}

int	main(void)
{
	p_striteri("aAkgasADF   2151kdaIWAh", reverse_case);
	p_striteri("", reverse_case);
	p_striteri("", NULL);
	p_striteri("asHK234 asdd*R@faF", NULL);
	p_striteri("asd*IYfG a &@jdLh;:fH", reverse_case);
	p_striteri("asdHKLLKH gal g21412r K:f", reverse_case);
	return (0);
} */
