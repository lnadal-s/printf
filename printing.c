/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:29:32 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:12:01 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printing(t_arg **lst)
{
	t_arg	*ptr;
	int		res;

	res = 0;
	if (!lst || !*lst)
		return (0);
	else
	{
		ptr = *lst;
		while (ptr)
		{
			write(1, ptr->res, ptr->len);
			res = res + ptr->len;
			ptr = ptr->next;
		}
	}
	return (res);
}
