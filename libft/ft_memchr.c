/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:28:02 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/22 15:38:14 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			k;
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	k = 0;
	while (k < n)
	{
		if (ptr[k] == (unsigned char)c)
			return ((void *)s + k);
		k++;
	}
	return (0);
}
