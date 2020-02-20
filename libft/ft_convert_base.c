/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:05:26 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 17:37:37 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		position(char c, char *base)
{
	int k;

	k = 0;
	while (base[k] != 0)
	{
		if (c == base[k])
			return (k);
		k++;
	}
	return (-1);
}

static int		ft_checkbase(char *base)
{
	int k;
	int j;

	k = 0;
	if (base[0] == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[k] != 0)
	{
		j = 1;
		if (base[k] == 32 || base[k] == '\t' || base[k] == '\n'
				|| base[k] == '\r'
				|| base[k] == '\v' || base[k] == '\f' || base[k] == '+'
				|| base[k] == '-' || base[k] > 126)
			return (0);
		while (base[k + j] != 0)
		{
			if (base[k] == base[k + j])
				return (0);
			j++;
		}
		k++;
	}
	return (1);
}

static int		ft_atoib(char *str, char *base_from)
{
	int					k;
	unsigned int		res;
	int					s;

	k = 0;
	res = 0;
	s = 1;
	while (str[k] != 0 && (str[k] == 32 || str[k] == '\n' || str[k] == '\t' ||
				str[k] == '\r' || str[k] == '\v' || str[k] == '\f'))
	{
		k++;
	}
	while (str[k] != 0 && (str[k] == '-' || str[k] == '+'))
	{
		if (str[k] == '-')
			s = -s;
		k++;
	}
	while (position(str[k], base_from) != -1)
	{
		res = res * ft_strlen(base_from) + position(str[k], base_from);
		k++;
	}
	return (res * s);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		k;
	int		nb;
	char	*tab;

	k = 0;
	if (base_from == 0 || base_to == 0)
		return (0);
	else if (ft_checkbase(base_from) == 1 && ft_checkbase(base_to) == 1)
	{
		nb = ft_atoib(nbr, base_from);
		tab = ft_dectobase(nb, base_to);
		return (tab);
	}
	return (0);
}
