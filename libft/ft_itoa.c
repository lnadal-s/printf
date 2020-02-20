/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:09:24 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/26 17:15:21 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_int(long n)
{
	int len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void		to_integer(char *integer, long m, int size)
{
	if (m == 0)
		integer[0] = '0';
	while (m > 0 && size >= 0)
	{
		integer[size] = '0' + (m % 10);
		m = m / 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	long			m;
	int				size;
	char			*integer;

	m = n;
	size = len_int(m);
	if (!(integer = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (m < 0)
	{
		m = m * (-1);
		integer[0] = '-';
	}
	integer[size] = 0;
	to_integer(integer, m, size - 1);
	return (integer);
}
