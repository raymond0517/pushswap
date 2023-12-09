/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 01:32:40 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 19:44:50 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = malloc((sizeof(struct s_list)));
	if (l != NULL)
	{
		l->next = NULL;
		l->content = content;
	}
	return (l);
}
/*
typedef struct
{
	size_t	stud_no;
	char	name[50];
	char	sex;
	size_t	age;
}	t_stud;

typedef	struct
{
	size_t	order_no;
	float	order_amt;
	char	order_date[8];
	char	cust_no[20];
}	t_order;

#include <string.h>
#include <stdio.h>
int	main(void)
{
	t_stud	*stud_1;
	t_order	*order_1;
	t_list	*stud;
	t_list	*order;
	t_stud	*stud_2;
	t_order	*order_2;

	stud_1 = malloc(sizeof(t_stud));
	if (stud_1)
	{
		stud_1->stud_no = 1355;
		strcpy(stud_1->name, "Lee Ah Bah");
		stud_1->sex = 'M';
		stud_1->age = 40;
		stud = ft_lstnew(stud_1);
	}
	order_1 = malloc(sizeof(t_order));
	if (order_1)
	{
		order_1->order_no = 12345;
		order_1->order_amt  = 103.2;
		strcpy(order_1->order_date, "20230514");
		strcpy(order_1->cust_no, "AB00031");
		order = ft_lstnew(order_1);
	}

	if (stud)
	{
		stud_2 = (t_stud *)stud->content;
		printf("\nstud num (%d) name (%s), sex (%c), age (%d)", \
		(int)stud_2->stud_no, stud_2->name, stud_2->sex, (int)stud_2->age);
	}
	if (order)
	{
		order_2 = (t_order *)order->content;
		printf("\norder num (%d), amt (%f), date (%s), cust num (%s)", \
		(int)order_2->order_no, order_2->order_amt, order_2->order_date,\
		order_2->cust_no);
	}
	return (0);
} */
