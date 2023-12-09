/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 23:04:16 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 19:50:10 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	l is exising linked list, pointer to f takes argument void *, 
	in our case, it is l->content, so it examines and modify content and 
	allocate memory for new content and returns it as void *.
	Pointer to del function also takes void * argument, in our case
	l->content, and it frees the content memory area if new linked list
	is successfully created and returned.
*/
t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	void	*retcontent;
	t_list	*r;
	t_list	*node;

	if ((l == NULL) || (f == NULL) || (del == NULL))
		return (NULL);
	r = NULL;
	while (l)
	{
		retcontent = f(l->content);
		if (retcontent != NULL)
			node = ft_lstnew(retcontent);
		if ((retcontent == NULL) || (node == NULL))
		{
			if (retcontent != NULL)
				free(retcontent);
			ft_lstclear(&r, del);
			return (NULL);
		}
		ft_lstadd_back(&r, node);
		l = l->next;
	}
	return (r);
}
