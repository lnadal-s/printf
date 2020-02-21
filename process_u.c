/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:59:54 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:18:09 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	process_u(t_print *tp, t_arg *arg)
{
	char			*nbr;
	unsigned int	n;

	if (alig_zero(arg) == 1)
		return (-1);
	get_star(tp, arg);
	if (!(n = va_arg(tp->ap, unsigned int)))
		nbr = get_spec(arg);// LEAKS ICI
	else
		nbr = ft_itoa(n);
	if (arg->is_prec == 1)
		arg->zero = 0;
	if (!(get_res_dec(nbr, arg)))
	{
		free(nbr);
		return (-1);
	}
	free(nbr);
	return (1);
}
