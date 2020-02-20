/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:00:41 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/28 12:03:53 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	k;

	k = 0;
	if (!n)
		return (0);
	while (s1[k] && s2[k] && s1[k] == s2[k] && k < n - 1)
		k++;
	return ((unsigned char)s1[k] - (unsigned char)s2[k]);
}
