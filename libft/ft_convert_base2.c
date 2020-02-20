/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 19:00:03 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 15:18:37 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tailletab(unsigned long int nbr, char *base)
{
	int		k;
	int		size;

	size = ft_strlen(base);
	k = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr = nbr / size;
		k++;
	}
	return (k);
}

void	convertbaseto(char *tab, char *base, unsigned long int nb, int s)
{
	int					reste;
	unsigned long int	nbr;
	unsigned long int	t;

	t = ft_strlen(base);
	if (nb < 0)
		nbr = -nb;
	else
		nbr = nb;
	tab[s] = 0;
	while (0 < s)
	{
		reste = nbr % t;
		nbr = nbr / t;
		tab[s - 1] = base[reste];
		s--;
	}
	if (nb < 0)
		tab[0] = '-';
}

char	*ft_dectobase(unsigned long int nb, char *base)
{
	int					sizetab;
	char				*tab;
	long int			n;

	if (nb < 0)
	{
		n = -nb;
		sizetab = ft_tailletab(n, base) + 1;
		if (!(tab = malloc(sizeof(char) * sizetab)))
			return (0);
	}
	else
	{
		sizetab = ft_tailletab(nb, base);
		if (!(tab = malloc(sizeof(char) * sizetab)))
			return (0);
	}
	convertbaseto(tab, base, nb, sizetab);
	return (tab);
}
