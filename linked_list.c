/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:12:54 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 12:30:18 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

size_t len_ll(t_arg **lst)
{
	size_t	k;
	t_arg	*ptr;

	k = 0;
	if (!lst || !*lst)
		return (0);
	ptr = *lst;
	while (ptr)
	{
		ptr = ptr->next;
		k++;
	}
	return (k);

}

void aff_lst(t_arg **lst)
{
	t_arg *ptr;
	//	int k = 0; 

	if (lst == NULL)
		return ;
	ptr = *lst;
	while (ptr)
	{
		//printf("---ARGUEMENT %d----\n", k++);
		if (ptr->is_convers == 0)
		{
			//ft_putstr_fd(ptr->res, 1);
			printf("%s", ptr->res);
		}
		else
		{
			printf("\n");
			//	printf("je print 2\n");
			aff_arg(ptr);

		}
		ptr=ptr->next;
	}
}

t_arg *init_arg()
{
	t_arg *elem;

	if (!(elem = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	elem->is_convers = -1;
	elem->alig = 0;
	elem->zero = 0;
	elem->width = 0;
	elem->prec = 0;
	elem->type = 0;
	elem->res = 0;
	elem->next = NULL;
	return (elem);
}

void aff_arg(t_arg *arg)
{
	int i = arg->is_convers;
	int a = arg->alig;
	int z = arg->zero;
	int w = arg->width;
	int p = arg->prec;
	char t = arg->type;
	printf("-------------ARG--------------\n");
	printf("conv:\t%d;\nalig:\t%d;\nzero?:\t%d;\nwidth:\t%d;\nprec:\t%d;\ntype:\t%c;\n", i, a, z, w, p, t);
	printf("-------------FIN--------------\n");
}

void add_c(t_arg **lst, t_arg *new)
{
	t_arg   *ptr;

	if (!(lst) || !new)
		return ;
	 if (!(*lst))
		*lst = new;
	else
	{
		ptr = *lst;
		if (ptr->next)
			while (ptr->next)
			{
				ptr = ptr->next;
			}
		ptr->next = new;
		new->next = 0;
	}
}

t_arg *arg_newc(char c)
{
	t_arg   *elem;
	char    *dst;

	if (c == 0)
		return (NULL);
	if (!(elem = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	dst[0] = c;
	dst[1] = 0;
	elem->res = dst;
	elem->next = 0;
	elem->is_convers = 0;
	elem->alig = 0;
	elem->zero = 0;
	elem->width = 0;
	elem->prec = 0;
	return (elem);
}
