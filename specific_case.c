/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:17:05 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:28:12 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		alig_zero(t_arg *arg)
{
	if (arg->alig == 1 && arg->zero == 1)
		return (1);
	return (0);
}

void	check_neg_width(t_arg *arg)
{
	if (arg->width < 0)
	{
		arg->width = -arg->width;
		arg->alig = 1;
	}
}
