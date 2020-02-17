/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:12:54 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/17 19:27:54 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void aff_lst(t_arg **lst)
{
	t_arg *ptr;

	if (lst == NULL)
		return ;
	ptr = *lst;
	while (ptr)
	{
		ft_putstr_fd(ptr->res, 1);
		ptr=ptr->next;
	}
}

void add_c(t_arg **lst, t_arg *new)
{
	t_arg   *ptr;
	
	if (!(lst))
		return ;
	else if (!(*lst))
		*lst = new;
	else
	{
		ptr = *lst;
		if (ptr->next)
			while (ptr->next)
				ptr = ptr->next;
		ptr->next = new;
		new->next = 0;
	}

}

t_arg *arg_newc(char c)
{
	t_arg   *elem;
	char    *dst;

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
	elem->str = NULL;
	return (elem);
}
