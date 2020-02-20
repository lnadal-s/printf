/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquisition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:26:35 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 16:57:22 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "libftprintf.h"

int is_flag(char c)
{
	char    flags[] = "cspdiuxX"; // FLAGS GERER
	int     k;

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
		//aff_arg(new);
	//	aff_lst(lst);
		add_c(lst, new);
		return (k + 1);
	}
	else
		return (-1);
}

size_t process_format(const char *s, t_arg **lst)
{
	size_t k;

	k = 0;
	while (s[k])
	{
	//	printf("k:%zu c: %c -<\n", k, s[k]);
		if (s[k] != '%')
			add_c(lst, arg_newc(s[k]));
		else if (s[k] == '%'  && s[k + 1] && s[k + 1] == '%')
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

int acquisition(const char *format, t_arg **lst)
{
	size_t      ret;
	size_t      size;
	size_t      res;

	if (!format || !lst)
		return (-1);
	size = ft_strlen(format);
	res = 0;
	ret = 0;
//	printf("size = %zu\n", size);
	while (ret < size) //verifier le strlen pour format = 0
	{
		ret = ret + process_format(format + ret, lst) + 1;
		//printf("ret: %zu\n", ret);
		if (ret < size && (res = check_conv(format + ret, lst)) == -1)
		{
		//	printf("leaving there\n");
			return (-1);
		}
//		printf("res:%zu\n", res);
		ret += res;
	}
	return (1);
}
