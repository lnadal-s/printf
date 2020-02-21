/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:12:54 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:11:24 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	len_ll(t_arg **lst)
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

t_arg	*init_arg(void)
{
	t_arg *elem;

	if (!(elem = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	elem->is_convers = -1;
	elem->alig = 0;
	elem->zero = 0;
	elem->width = 0;
	elem->neg = 0;
	elem->prec = 0;
	elem->is_prec = 0;
	elem->type = 0;
	elem->res = 0;
	elem->next = NULL;
	return (elem);
}

void	add_c(t_arg **lst, t_arg *new)
{
	t_arg *ptr;

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

t_arg	*arg_newc(char c)
{
	t_arg	*elem;
	char	*dst;

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
	elem->len = 1;
	return (elem);
}
