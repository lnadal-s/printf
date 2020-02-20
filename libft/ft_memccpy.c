/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:23:30 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/22 15:27:39 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*dest;
	size_t			k;

	ptr = (unsigned char*)src;
	dest = (unsigned char*)dst;
	k = 0;
	while (k < n)
	{
		dest[k] = ptr[k];
		if (ptr[k] == (unsigned char)c)
			return (dst + k + 1);
		k++;
	}
	return (NULL);
}
