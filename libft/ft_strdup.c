/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:32:10 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/17 09:09:24 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*ptr;
	size_t	size;

	size = ft_strlen(s);
	ptr = (char *)s;
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(dest, ptr, size + 1);
	return (dest);
}
