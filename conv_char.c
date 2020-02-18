/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:02:15 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 17:16:39 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

void get_res_c(t_print tp, t_arg *arg)
{

}

int process_c(t_print *tp, t_arg *arg)
{
	if (alig_zero(arg) == 1)
		return (-1);
	if (arg->prec != 0 || arg->zero != 0)
		return (-1);
	if (prec->width == -1)
		prec->width = va_arg(tp->ap, int);
	get_res_c(tp, arg);
	return (1);
}
