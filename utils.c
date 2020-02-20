/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 09:46:51 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 19:09:49 by lnadal-s         ###   ########.fr       */
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
		res = -1;
	}
	return (res);
}

char *get_spec(t_arg *arg)
{
	 if (arg->is_prec == 1)
		 return (ft_strdup(""));
	 return (ft_strdup("0"));
}

char *put_neg(t_arg *arg, char *dst, int indice, int size)
{
	char *str;

	if (arg->neg == 0)
		return (dst);
	if (arg->width > size && indice == 1)
	{
		dst[0] = '-';
		return (dst);
	}
	else
	{
		str = ft_strjoin("-", dst);
		free(dst);
		return (str);
	}
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
