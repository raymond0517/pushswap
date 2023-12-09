/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:48:47 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 19:48:06 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	t = *lst;
	while (t != NULL)
	{
		if (t->next == NULL)
		{
			t->next = new;
			return ;
		}
		else
			t = t->next;
	}
	*lst = new;
	return ;
}
