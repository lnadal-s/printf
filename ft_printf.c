/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:35:06 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 12:41:18 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char* format, ...)
{
	t_print		*tp;
	int			ret;
	t_arg  **lst;


	if (!(tp = (t_print *)malloc(sizeof(t_print))))
		return (-1);
	va_start(tp->ap, format);
	if (!(lst = (t_arg**)malloc(sizeof(t_arg*))))
		return (-1); //free tp
	*lst = 0;
	tp->lst = lst;
	if (acquisition(format, lst) == -1)
		return (clear_sp(tp));
	//printf("before\n");
	ret = process(tp);
	//printf("after process\n");
	//printf("ret = %d\n", ret);
	if (ret == -1)
		return (clear_sp(tp));
	va_end(tp->ap);
	printing(lst);
	clear_sp(tp);
	return (ret);
}
