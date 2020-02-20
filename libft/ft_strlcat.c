/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:58:13 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/17 10:14:26 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t k;
	size_t j;

	j = 0;
	k = 0;
	i = 0;
	while (dst[k] != 0)
		k++;
	while (src[j] != 0)
		j++;
	if (size < k + 1)
		return (size + j);
	while ((i < size - 1 - k) && (src[i] != 0))
	{
		dst[k + i] = src[i];
		i++;
	}
	dst[k + i] = 0;
	return (k + j);
}
