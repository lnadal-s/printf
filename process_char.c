/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:02:15 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:13:10 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

char	*add_char(char c, char *str, int align)
{
	int		k;
	char	*dst;
	int		size;

	size = ft_strlen(str);
	k = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 2))))
		return (0);
	if (align == 1)
	{
		dst[0] = c;
		ft_strlcpy(dst + 1, str, size + 1);
	}
	else
	{
		ft_strlcpy(dst, str, size + 1);
		dst[size] = c;
		dst[size + 1] = 0;
	}
	return (dst);
}

int		get_res_c(t_print *tp, t_arg *arg)
{
	char	*w;
	char	*dst;
	char	c;

	if (!(w = alloc_char(' ', arg->width - 1)))
		return (0);
	c = (char)va_arg(tp->ap, int);
	dst = add_char(c, w, arg->alig);
	arg->res = dst;
	arg->len = ft_strlen(dst);
	if (c == 0)
		arg->len = 1 + ft_strlen(w);
	free(w);
	return (1);
}

int		process_c(t_print *tp, t_arg *arg)
{
	if (alig_zero(arg) == 1)
		return (-1);
	if (arg->prec != 0 || arg->zero != 0)
		return (-1);
	if (arg->width == -1)
		arg->width = va_arg(tp->ap, int);
	check_neg_width(arg);
	if (!(get_res_c(tp, arg)))
		return (-1);
	return (1);
}
