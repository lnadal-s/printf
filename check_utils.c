/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:50:14 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:04:32 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		check_alig_zero(const char *str, t_arg *arg)
{
	int k;

	k = 0;
	while (str[k] && ((str[k] == '0') || (str[k] == '-')))
	{
		if (str[k] == '-')
			arg->alig = 1;
		if (str[k] == '0')
			arg->zero = 1;
		k++;
	}
	return (k);
}

int		check_width(const char *str, t_arg *arg)
{
	int k;

	k = 0;
	if (str[k] && str[k] == '*')
	{
		arg->width = -1;
		k = 1;
	}
	else
	{
		arg->width = ft_atoi(str + k);
		while (str[k] && ft_isdigit(str[k]))
			k++;
	}
	return (k);
}

int		check_prec(const char *str, t_arg *arg)
{
	int k;

	k = 1;
	if (str[0] != '.')
		return (0);
	else
	{
		if (str[k] && str[k] == '*')
		{
			arg->prec = -1;
			k++;
		}
		else
		{
			arg->prec = ft_atoi(str + k);
			arg->is_prec = 1;
			while (str[k] && ft_isdigit(str[k]))
				k++;
		}
	}
	return (k);
}

int		check_flag(const char c, t_arg *arg)
{
	if (is_flag(c))
	{
		arg->type = c;
		arg->is_convers = 1;
		return (1);
	}
	else
		return (0);
}
