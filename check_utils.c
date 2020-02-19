/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:50:14 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 12:43:17 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int check_alig(const char *str, t_arg *arg)
{
	int k;

	k = 0;
	while (str[k] && str[k] == '-')
		k++;
	if (k != 0)
		arg->alig = 1;
	return (k);
}

int check_zero(const char *str, t_arg *arg)
{
	int k;

	k = 0;

	while (str[k] && str[k] == '0')
		k++;
	if (k != 0)
		arg->zero = 1;
	return (k);
}

int check_width(const char *str, t_arg *arg)
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
		arg->width = ft_atoi(str + k); //attention a cet atoi il ne doit pas y avoir d' espace ni ce + ni de -
		while (str[k] && ft_isdigit(str[k]))
			k++;
	}
	return (k);
}

int check_prec(const char *str, t_arg *arg)
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
			while (str[k] && ft_isdigit(str[k]))
				k++;
		}
	}
	return (k);
}

int check_flag(const char c, t_arg *arg)
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
