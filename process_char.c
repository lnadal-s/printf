/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:02:15 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 18:06:07 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int get_res_c(t_print *tp, t_arg *arg)
{
	char *w;
	char *dst;
	char *c;

	if (!(w = alloc_char(' ', arg->width - 1)))
		return (0);
	if (!(c = alloc_char((char)va_arg(tp->ap, int), 1)))
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

//process char -> mettre le get-start tout de suite apres alig zero
int process_c(t_print *tp, t_arg *arg)
{
	if (alig_zero(arg) == 1)
		return (-1);
	if (arg->prec != 0 || arg->zero != 0)
		return (-1);
	if (arg->width == -1)
		arg->width = va_arg(tp->ap, int);
	//printf("w:%d\n", arg->width);
	check_neg_width(arg);
	if (!(get_res_c(tp, arg)))
		return (-1);
	return (1);
}
