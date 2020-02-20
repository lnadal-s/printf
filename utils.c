/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:46:51 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 10:33:17 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int get_star(t_print *tp, t_arg *arg)
{
	int res;
	
	res = 0;
	if (arg->width == -1)
		arg->width = (int)va_arg(tp->ap, int);
	if (arg->width < 0)
	{
		printf("oui\n");
		arg->width = - arg->width;
		arg->alig = 1;
		arg->zero = 0;
		res = 1;
	}
	if (arg->prec == -1)
	{
		arg->prec = (int)va_arg(tp->ap, int);
		arg->is_prec = 1;
	}
	if (arg->prec < 0)
	{
		arg->prec = - arg->prec;
		arg->is_prec = 0;
		//arg->align = 1;
		res = -1;
	}
	return (res);
}

char *alloc_char(char c, int size)
{
	char	*dst;
	int		k;

	k = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (k < size)
	{
		dst[k] = c;
		k++;
	}
	dst[k] = 0;
	return (dst);
}
