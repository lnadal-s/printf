/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:50:14 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 12:03:36 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int check_alig(char *str, t_arg *arg)
{
	int k;

	k = 0;
	while (str[k] && str[k] == '-')
		k++;
	if (k != 0)
		arg->alig = 1;
	return (k);
}

int check_zero(char *str, t_arg *arg)
{
	int k;

	k = 0;

	while (str[k] && str[k] == '0')
		k++;
	if (k != 0)
		arg->zero = 1;
	return (k);
}

int check_width(char *str, t_arg *arg)
{
	int k;

	k = 0;
	if (str[k] && str[k] == '*')
	{
		new->width = -1;
		k = 1;
	}
	else
	{
		new_width = ft_atoi(str + k); //attention a cet atoi il ne doit pas y avoir d' espace ni ce + ni de -
		while 
	}

}
