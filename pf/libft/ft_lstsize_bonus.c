/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 02:15:04 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 19:47:05 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*ptr;

	cnt = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		cnt++;
		ptr = ptr->next;
	}
	return (cnt);
}
