/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:00:48 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/17 09:10:28 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		k;
	int		res;
	char	*ptr;

	ptr = (char *)s;
	k = 0;
	res = -1;
	while (ptr[k])
	{
		if (ptr[k] == (unsigned char)c)
			res = k;
		k++;
	}
	if (c == ptr[k])
		return (ptr + k);
	else if (res != -1)
		return (ptr + res);
	else
		return (0);
}
