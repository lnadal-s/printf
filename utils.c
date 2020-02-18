/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:56:04 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 18:20:05 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *alloc_char(char c, int size)
{
	char	*dst;
	int		k;

	k = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (k < size)
	{
		dst[k] = c;
		k++;
	}
	dst[k] = 0;
	return (dst);
}
