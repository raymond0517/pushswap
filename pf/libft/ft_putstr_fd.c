/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:24:04 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/20 18:47:02 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
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
	ft_putstr_fd("", f);
	ft_putstr_fd("()", f);
	ft_putstr_fd("We are the champions my friend", f);
	ft_putstr_fd("first", 1);
	ft_putstr_fd("\nSecond", 1);
	ft_putstr_fd("\nThird", 1);
	ft_putstr_fd("error 1", 2);
	ft_putstr_fd("\nerror 2", 2);
	ft_putstr_fd("\nerror 3", 2);
	close(f);
	return (0);
} */
