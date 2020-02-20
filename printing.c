/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:29:32 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 15:55:24 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int printing(t_arg **lst)
{
	t_arg *ptr;
	int res;

	res = 0;
	if (!lst || !*lst)
		return (0);
	else
	{
		ptr = *lst;
		while (ptr)
		{
			
		//	printf("%s\n", ptr->res);
			ft_putstr_fd(ptr->res, 1);
			res = res + ptr->len;
			ptr = ptr->next;
		}
	}
	return (res);
}
