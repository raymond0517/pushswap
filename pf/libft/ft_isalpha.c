/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 04:24:38 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/07 15:55:20 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("test A Z, a, z @, [, ` , { , \\t %d, %d, %d, %d, %d, %d, %d, %d, %d"\
	 , ft_isalpha('A'), ft_isalpha('Z'), ft_isalpha('a'), \
	ft_isalpha('z'), ft_isalpha('@'), ft_isalpha('['), ft_isalpha('`'), \
	ft_isalpha('{'), ft_isalpha('\t'));
	printf("\n");
	return (0);
} */
