/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 02:32:56 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 19:49:11 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	delnode(t_list *lst, void (*del)(void *))
{
	if (lst->next != NULL)
	{
		delnode(lst->next, del);
	}
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((lst == NULL) || ((*lst) == NULL) || (del == NULL))
		return ;
	delnode(*lst, del);
	*lst = NULL;
}
