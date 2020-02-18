/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:59:03 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 12:03:38 by lnadal-s         ###   ########.fr       */
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
	char	flags[] = "cspdiuxX"; // FLAGS GERER
	int		k;
	
	k = 0;
	while (flags[k])
	{
		if (flags[k] == c)
			return (1);
		k++;
	}
	return (0);
}

t_arg *check_conv(char *str)
{
	int k;
	t_arg *new;
	
	k = 0;
	new = init_arg();
	k += check_alig(str, new);
	k += check_zero(str, new);
	if (str[k] == '*')
	{
		new->width = -1;
		k++;
	}
	else
	{
		new->width = ft_atoi(str + k); //attention a cet atoi il ne doit pas y avoir d' espace ni ce + ni de -
	while (str[k] && ft_isdigit(str[k]))
		k++;
	}
	if (str[k] && str[k] == '.' && str[k + 1])
	{
		k++;
		if (str[k] == '*')
		{
			new->prec = -1;
			k++;
		}
		else
			new->prec = ft_atoi(str + k); //attention a cet atoi il ne doit pas y avoir d' espace ni ce + ni de -
	}
	while (str[k] && ft_isdigit(str[k]))
		k++;
	if (is_flag(str[k]))
	{
		new->type = str[k];
		new->is_convers = 1;
	}
	aff_arg(new);
	return (new);
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
			add_c(lst, arg_newc('%'));
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
	size_t		ret;
	t_arg		**lst;

	va_start(ap, format);
	ret = 0;
	if (!(lst = (t_arg **)malloc(sizeof(t_arg *))))
		return (-1);
	while (ret != ft_strlen(format)) //verifier le strlen pour format = 0
	{
		ret = ret + parsing(format + ret, lst);
	}
	va_end(ap);
	return (0);
}
