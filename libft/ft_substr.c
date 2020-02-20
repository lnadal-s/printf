/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:05:21 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/26 15:29:19 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	k;
	int		size;

	k = 0;
	if (s == 0)
		return (NULL);
	size = ft_strlen(s);
	if (start > ft_strlen(s))
		return (ptr = ft_calloc(1, 1));
	if (len > size - start)
		len = size - start;
	if (!(ptr = (char *)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	while (k < len)
	{
		ptr[k] = s[start + k];
		k++;
	}
	ptr[k] = 0;
	return (ptr);
}
