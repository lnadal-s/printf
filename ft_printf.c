/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:35:06 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:07:39 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	t_print		*tp;
	t_arg		**lst;
	int			ret;

	if (!(tp = (t_print *)malloc(sizeof(t_print))))
		return (-1);
	if (!(lst = (t_arg**)malloc(sizeof(t_arg*))))
	{
		free(tp);
		return (-1);
	}
	*lst = 0;
	tp->lst = lst;
	va_start(tp->ap, format);
	if (acquisition(format, lst) == -1)
		return (clear_sp(tp));
	ret = process(tp);
	if (ret == -1)
		return (clear_sp(tp));
	va_end(tp->ap);
	ret = printing(lst);
	clear_sp(tp);
	return (ret);
}
