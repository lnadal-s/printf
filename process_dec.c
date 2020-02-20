/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:45:45 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 09:36:53 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int get_prec(t_arg *arg, char *dst, int size)
{
	char *prec;

	if (!(w = alloc_char('o', size)))
}

int get_res_dec(char *nbr, t_arg *arg)
{
	char z;
	char sp;
	char *w;
	char *dst;
	int size;
	
	size = (int)ft_strlen(nbr);
	if (arg->is_prec == 1)
		size = arg->prec > size ? arg->prec : size;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	dst = ft_strlcpy(dst, nbr, size + 1);
	get_prec(arg, dst, size);

	if (arg->alig == 1 || arg->is_prec == 1)
		sp = ' ';
	else if (arg->is_prec == 0 && arg->zero == 1)
		sp = '0';
	if (arg-
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
