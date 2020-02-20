/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:49:53 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 15:53:07 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int process_x(t_print *tp, t_arg *arg, int indice)
{
	char *base;
	char *tmp;
	char *nbr;
	unsigned int u;

	if (alig_zero(arg) == 1)
		return (-1);
	if (indice == 1)
		base ="0123456789abcdef";
	else
		base ="0123456789ABCDEF";
	get_star(tp, arg);
	if (arg->is_prec == 1)
		arg->zero = 0;
	u = va_arg(tp->ap, unsigned int);
	nbr = ft_itoa(u);
	tmp = nbr;
	nbr = ft_convert_base(nbr, "0123456789", base);
	free(tmp);
	if (!(get_res_dec(nbr, arg)))
	{
		free(nbr);
		return (-1);
	}
	free(nbr);
	return (1);
}
