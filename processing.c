/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:53:26 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 12:56:15 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int process_and_type(t_print *tp, t_arg *ptr)
{
	if (ptr->is_convers < 1)
		return (ptr->is_convers);
	else if (ptr->type == 'c')
		return (process_c(tp, ptr));
	else if (ptr->type == 's')
		return (process_str(tp, ptr));
	return (1);
/*		else if (ptr->type = "p")
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
*/}

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
	return (1);
}
