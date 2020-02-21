/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 11:49:53 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:26:32 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_nbr(t_arg *arg, unsigned int u, char *base)
{
	char *nbr;
	char *tmp;

	if (u > 0)
	{
		nbr = ft_itoa(u);
		tmp = nbr;
		nbr = ft_convert_base(nbr, "0123456789", base);
		free(tmp);
	}
	else
		nbr = get_spec(arg);
	return (nbr);
}

int		process_x(t_print *tp, t_arg *arg, int indice)
{
	char *base;
	char *nbr;

	if (alig_zero(arg) == 1)
		return (-1);
	if (indice == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	get_star(tp, arg);
	if (arg->is_prec == 1)
		arg->zero = 0;
	nbr = get_nbr(arg, va_arg(tp->ap, unsigned int), base);
	if (!(get_res_dec(nbr, arg)))
	{
		free(nbr);
		return (-1);
	}
	free(nbr);
	return (1);
}
