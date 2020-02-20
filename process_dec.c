/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_dec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:45:45 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 11:47:01 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *get_prec(t_arg *arg, char *nbr)
{
	char *p;
	int size;
	int prec;
	char *dst;

	if (arg->is_prec == 0)
		return (ft_strdup(nbr));
	size = (int)ft_strlen(nbr);
	prec = size > arg->prec ? 0 : arg->prec - size;
	if (!(p = alloc_char('0', prec)))
		return (0);
	if (!(dst = ft_strjoin(p, nbr)))
	{
		free(p);
		return (0);
	}
	free(p);
	return (dst);
}

char *get_alig(t_arg *arg, char *dst)
{
	char sp;
	char *w;
	int size;
	char *str;

	if (arg->width == 0)
		return (dst);
	size = ft_strlen(dst);
	size = size > arg->width ? 0 : arg->width - size;
	if (arg->alig == 1 || arg->is_prec == 1)
		sp = ' ';
	if (arg->is_prec == 0 && arg->zero == 1)
		sp = '0';
	if (!(w = alloc_char(sp, size)))
	{
		free(dst);
		return (0);
	}
	if (arg->alig == 0)
		str = ft_strjoin(w, dst);
	else
		str = ft_strjoin(dst, w);
	free(dst);
	free(w);
	return (str);
}

int get_res_dec(char *nbr, t_arg *arg)
{
	char *dst;
	
	if (!(dst = get_prec(arg, nbr)))
		return (0);
	if (!(dst = get_alig(arg, dst)))
		return (0);
	arg->res = dst;
	arg->len = ft_strlen(dst);
	return (1);
}

int process_dec(t_print *tp, t_arg *arg)
{
	char *nbr;

	if (alig_zero(arg) == 1)
		return (-1);
	get_star(tp, arg);
	nbr = ft_itoa(va_arg(tp->ap, int)); //MALLOC ICI
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
