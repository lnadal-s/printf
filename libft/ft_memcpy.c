/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:52:22 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/01 17:55:48 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	k;
	char	*ptr;
	char	*dst;

	ptr = (char*)src;
	dst = (char*)dest;
	k = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (k < n)
	{
		dst[k] = ptr[k];
		k++;
	}
	return (dest);
}
