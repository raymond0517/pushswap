/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:46 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 04:25:44 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			cnt;
	unsigned char	*s;
	unsigned char	*d;

	cnt = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if ((dest == NULL) && (src == NULL))
		return (dest);
	while (cnt < n)
	{
		d[cnt] = s[cnt];
		cnt++;
	}
	return (dest);
}
