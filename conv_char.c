/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:02:15 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 18:20:10 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int get_res_c(t_print tp, t_arg *arg)
{
	char *w;
	char *dst;
	char *tmp;
	char *c;

	if (!(w = alloc_char(' ', arg->width)))
		return (0);
	if (!(c = alloc_char(va_arg(tp->ap - 1, char), 1)))
	{
		free(w);
		return (0);
	}
	if (arg->alig == 0)
		dst = ft_strjoin(w, c);
	else
		dst = ft_strjoin(c, w);
	free(c);
	free(w);
	arg->res = dst;
	return (1);
}

int process_c(t_print *tp, t_arg *arg)
{
	if (alig_zero(arg) == 1)
		return (-1);
	if (arg->prec != 0 || arg->zero != 0)
		return (-1);
	if (prec->width == -1)
		prec->width = va_arg(tp->ap, int);
	if (!(get_res_c(tp, arg)))
		return (-1);
	return (1);
}
