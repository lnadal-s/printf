/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:51:24 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/01 18:40:20 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dest;
	char		*str;
	size_t		k;

	dest = (char*)dst;
	str = (char *)src;
	k = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	if (dst > src)
	{
		while (k <= n)
		{
			dest[n - k] = str[n - k];
			k++;
		}
	}
	return (dst);
}
