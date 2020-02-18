/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:59:03 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 14:59:35 by lnadal-s         ###   ########.fr       */
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

int check_conv(const char *str, t_arg **lst)
{
	int k;
	t_arg *new;
	
	k = 0;
	new = init_arg();
	k += check_alig(str, new);
	k += check_zero(str + k, new);
	k += check_width(str + k, new);
	k += check_prec(str + k, new);
	if (check_flag(str[k], new))
	{
		add_c(lst, new);
		return (k + 1);
	}
	else
		return (-1);
}

int process_S(const char *s, t_arg **lst)
{
	int k;

	k = 0;
	while (s[k])
	{
		if (s[k] != '%')
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

int get_val(const char* format)
{
	t_arg **lst;
	int ret;

	if (!(lst = (t_arg **)malloc(sizeof(t_arg *))))
		return (-1);
	*lst = NULL;
	ret = get_convlst(format, lst);
	aff_lst(lst);
	return (ret);
}

int get_convlst(const char *format, t_arg **lst)
{	
	size_t		ret;
	size_t		size;
	size_t		res;

	ret = 0;
	size = ft_strlen(format);
	while (ret != size) //verifier le strlen pour format = 0
	{
		ret +=  process_S(format + ret, lst) + 1;
		if ((res = check_conv(format + ret, lst)) == -1)
			return (-1);
		printf("res:%zu\n", res);
		ret += res;
	}
	return (1);
}
