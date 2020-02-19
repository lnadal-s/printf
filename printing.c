/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:29:32 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 11:43:00 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int printing(t_arg **lst)
{
	t_arg *ptr;

	if (!lst || !*lst)
		return (0);
	else
	{
		ptr = *lst;
		while (ptr)
		{
			
		//	printf("%s\n", ptr->res);
			ft_putstr_fd(ptr->res, 1);
			ptr = ptr->next;
		}
	}
	return (1);
}
