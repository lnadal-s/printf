/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:17:05 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 15:24:39 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int alig_zero(t_arg *arg) //si align et zero sont en flag
{
	if (arg->alig == 1 && arg->zero == 1)
		return (1);
	return (0)
}
