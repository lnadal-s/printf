/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:45:45 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 18:20:25 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int get_res_dec(char *nbr, t_arg *arg)
{
	char z;
	char sp;
	char *w;
	char *dst;
	int size;

	if (arg->alig == 1)
		sp = ' ';
	else if (arg->zero == 1)
		sp = '0';
	size = (int)ft_strlen(nbr);
	if (arg->is_prec == 1)
		size = arg->prec > size ? arg->prec : size;
	if (!(dst = (char *)
}

int process_dec(t_print *tp, t_arg *arg)
{
	char *nbr;

	if (alig_zero(arg) == 1)
		return (-1);
	get_star(tp, arg);
	nbr = ft_itoa(va_arg(tp->ap, char *));
	if (arg->is_prec == 1)
		arg->zero == 0;
	if (!(get_res_dec(char *nbr, t_arg *arg)))
		return (-1);
	return (1);
}
