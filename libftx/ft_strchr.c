/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:03:35 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/22 16:04:29 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		k;
	char	*ptr;

	k = 0;
	ptr = (char *)s;
	while (ptr[k])
	{
		if (ptr[k] == (unsigned char)c)
			return (ptr + k);
		k++;
	}
	return (c == ptr[k] ? ptr + k : 0);
}
