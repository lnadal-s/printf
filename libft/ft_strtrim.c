/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:00:00 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/26 15:39:44 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int k;

	k = 0;
	while (set[k])
	{
		if (set[k] == c)
			return (1);
		k++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t size;
	size_t k;

	k = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[k] && is_set(s1[k], set))
		k++;
	size = ft_strlen(s1);
	if (k == size)
		return ((char *)ft_calloc(1, 1));
	start = k;
	k = size - 1;
	while (is_set(s1[k], set))
		k--;
	return (ft_substr(s1, start, k - start + 1));
}
