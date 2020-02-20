/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:55:54 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 19:13:08 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	int v;
	int d;
	
	printf("\n---------MA FONCTION---------\n");
	d = ft_printf("%.x %s", 0, "salut");
	
	printf("\n---------VRAI FONCTION---------\n");
	v = printf("%.x",  0);
	
	printf("\n--------- RESULTATS ---------\n");
	printf("\nvft:%d vprintf: %d\n", d, v);
	
	//printf("%-0.*s", 6, "oui");
}
