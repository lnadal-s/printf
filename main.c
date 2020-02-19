/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:55:54 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/19 17:47:57 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main()
{
	int v;
	int d;
	char *to_print = "bonjour";
	printf("\n---------MA FONCTION---------\n");
	d = ft_printf("%10.s",to_print);
	printf("\n---------VRAI FONCTION---------\n");
	v = printf("%.s", to_print );
	printf("\n--------- RESULTATS ---------\n");
	printf("\nvft:%d vprintf: %d\n", d, v);
	
	//printf("%-0.*s", 6, "oui");
}
