/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:03:09 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/01 16:52:02 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int j;
	unsigned int i;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < n && s1[i])
	{
		j = 0;
		while (i + j < n && s1[i + j] == s2[j])
		{
			if (!s2[j + 1])
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
