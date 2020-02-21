/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:13:38 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:05:13 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	del_one(t_arg *arg)
{
	if (arg->is_convers == 0)
	{
		free(arg->res);
		arg->res = 0;
	}
	else if (arg->is_convers == 1)
	{
		if (arg->res != 0)
		{
			free(arg->res);
			arg->res = 0;
		}
	}
	free(arg);
	arg = 0;
}

void	clear_s_arg(t_arg **lst)
{
	t_arg *ptr;
	t_arg *tmp;

	if (lst == NULL)
		return ;
	else
	{
		ptr = *lst;
		while (ptr)
		{
			tmp = ptr->next;
			del_one(ptr);
			ptr = tmp;
		}
	}
	free(lst);
	lst = 0;
}

int		clear_sp(t_print *tp)
{
	clear_s_arg(tp->lst);
	free(tp);
	tp = 0;
	return (-1);
}
