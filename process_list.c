/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:02:57 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 16:58:02 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int process_and_type(t_print *tp, t_arg *ptr)
{
	if (ptr->is_convers < 1)
		return (ptr->is_convers);
	else if (ptr->type = "c")
		return (process_c(tp, arg));
	else if (ptr->type = "s")
		return ();
	else if (ptr->type = "p")
		return();
	else if (ptr->type = "d")
		return ();
	else if (ptr->type = "i")
		return ();
	else if (ptr->type = "o")
		return ();
	else if (ptr->type = "u")
		return ();
	else if (ptr->type = "x")
		return ();
	else if (ptr->type = "X")
		return ();
}

int process(t_print *tp)
{
	t_arg *ptr;

	if (tp->lst == NULL)
		return (-1);
	ptr = *(tp->lst);
	while (ptr)
	{
		if (process_and_type(tp, ptr) == -1)
			return (-1);
		ptr = ptr->next;
	}
}
