/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:01 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/17 10:09:27 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;
	char			c;

	if (n < 0)
	{
		m = -n;
		write(fd, "-", 1);
	}
	else
		m = n;
	if (m > 9)
		ft_putnbr_fd(m / 10, fd);
	m = m % 10;
	c = '0' + m;
	write(fd, &c, 1);
}
