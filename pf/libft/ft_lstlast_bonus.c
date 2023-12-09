/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 03:01:40 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 19:47:33 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*r;

	r = lst;
	while (r != NULL)
	{
		if (r->next == NULL)
			return (r);
		else
			r = r->next;
	}
	return (r);
}
