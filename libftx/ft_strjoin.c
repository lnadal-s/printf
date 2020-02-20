/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:04:36 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/26 15:28:56 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	k;
	size_t	j;
	size_t	len;

	k = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	while (s1[k] && k < len)
	{
		ptr[k] = s1[k];
		k++;
	}
	while (s2[j] && k < len)
		ptr[k++] = s2[j++];
	ptr[k] = 0;
	return (ptr);
}
