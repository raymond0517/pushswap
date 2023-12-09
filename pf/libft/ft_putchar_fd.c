/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 03:14:05 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/20 04:08:05 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	f;

	f = open("test", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (f == -1)
	{
		printf("\nopen test file error");
		return (0);
	}
	ft_putchar_fd('H', f);
	ft_putchar_fd('i', f);
	ft_putchar_fd('\n', f);
	ft_putchar_fd('H', 1);
	ft_putchar_fd('i', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('H', 2);
	ft_putchar_fd('i', 2);
	ft_putchar_fd('\n', 2);
	close(f);
	return (0);
} */
