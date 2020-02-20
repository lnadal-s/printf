/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:59:17 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/22 15:46:36 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	k;
	char	*ptr;

	k = 0;
	ptr = (char *)s;
	while (k < n)
	{
		*(ptr + k) = 0;
		k++;
	}
}