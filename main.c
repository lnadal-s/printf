/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:55:54 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 16:12:59 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	int v;
	int d;
	int q;
	int *p;
	int intmin = -2147483648;
	q = 3;
	p = &q;
	printf("\n---------MA FONCTION---------\n");
	d = ft_printf("%-*p | %0*.*d asdas %u%i", 20 , p, 19, 17, intmin, 2147483647, 0);
	d = ft_printf("%i\n", 0);
	printf("\n---------VRAI FONCTION---------\n");
	v = printf("%-*p | %0*.*d asdas %u%i", 20, p, 19, 17,intmin, 2147483647, 0);
	v = printf("%i\n", 0);
	printf("\n--------- RESULTATS ---------\n");
	printf("\nvft:%d vprintf: %d\n", d, v);
	
	//printf("%-0.*s", 6, "oui");
}
