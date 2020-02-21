/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:53:26 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:58:12 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	process_and_type(t_print *tp, t_arg *ptr)
{
	if (ptr->is_convers < 1)
		return (ptr->is_convers);
	else if (ptr->type == 'c' || ptr->type == '%')
		return (process_c(tp, ptr));
	else if (ptr->type == 's')
		return (process_str(tp, ptr));
	else if (ptr->type == 'd' || ptr->type == 'i')
		return (process_dec(tp, ptr));
	else if (ptr->type == 'x')
		return (process_x(tp, ptr, 1));
	else if (ptr->type == 'X')
		return (process_x(tp, ptr, 0));
	else if (ptr->type == 'u')
		return (process_u(tp, ptr));
	else if (ptr->type == 'p')
		return (process_p(tp, ptr));
	return (1);
}

int	process(t_print *tp)
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
