/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:59:03 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/17 19:28:01 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int is_conv(char c, char to_find)
{
	if (to_find == c)
		return (1);
	return (0);
}

int is_flag(char c)
{

}

int is_conv(char *str)
{
	int k;
	int res;

	while (str[k] && is_conv(str[k], '-'))
		k++;
	if (str[k]
	while (str[k] && is_conv(str[k], '))
}

int parsing(const char *s, t_arg **lst)
{
	int k;

	k = 0;
	while (s[k])
	{
		if (!is_conv(s[k], '%'))
			add_c(lst, arg_newc(s[k]));
		else if (is_conv(s[k], '%')  && s[k + 1] && is_conv(s[k + 1], '%'))
		{
			k++;
			add_c(lst, arg_newc(s[k]));
		}
		else
			return (k);
		k++;
	}
	return (k);
}

int ft_printf(const char *format, ...)
{	
	va_list 	ap;
	int			ret;
	t_arg		**lst;

	va_start(ap, format);
	ret = 0;
	if (!(lst = (t_arg **)malloc(sizeof(t_arg *))))
		return (-1);
	while (ret != ft_strlen(format)) //verifier le strlen pour format = 0
	{
		ret = parsing(s + ret, lst);
		va_arg(ap)
	}
	va_end(ap);
	return (0);
}
