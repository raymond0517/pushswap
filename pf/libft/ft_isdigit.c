/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 04:25:13 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 01:27:13 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return ((c >= 48) && (c <= 57));
}
/*
#include	<stdio.h>

int	main(void)
{
	printf("0x2f 0x30 0x0130 0xff30 0x39 0x3a  %d %d %d %d %d %d", \
	ft_isdigit(0x2f), \
	ft_isdigit(0x30), \
	ft_isdigit(0x0130), \
	ft_isdigit(0xff30), \
	ft_isdigit(0x39), \
	ft_isdigit(0x3a));
	return (0);
} */
