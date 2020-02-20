/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:06:09 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 17:25:40 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int get_addr(t_arg *arg, char *adr)
{
	char *dst;

	if (!(dst = ft_strjoin("0x", adr)))
		return (0);
	if (!(dst = get_alig(arg, dst)))
		return (0);
	free(adr);
	arg->res = dst;
	arg->len = ft_strlen(dst);
	return (1);

}

int process_p(t_print *tp, t_arg *arg)
{
	unsigned long adr;
	char *nbr;
	char *tmp;

	if (arg->zero == 1 || arg->is_prec == 1)
		return (-1);
	get_star(tp, arg);
	adr = va_arg(tp->ap, unsigned long);
	nbr = ft_itoa(adr);
	tmp = nbr;
	nbr = ft_convert_base(nbr, "0123456789", "0123456789abcdef");
	if (!(get_addr(arg, nbr)))
		return (-1);
	return (1);
}
