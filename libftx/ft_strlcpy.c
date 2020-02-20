/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:02:33 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/30 10:11:54 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (src)
	{
		if (size > 0)
		{
			while (src[i] != 0 && i < size - 1)
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = 0;
		}
		while (src[i] != 0)
			i++;
	}
	return (i);
}
