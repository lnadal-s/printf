/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:08:29 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/17 18:07:36 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "libftprintf.h"
int main()
{
	t_arg *lst;
	t_arg elem1;
	t_arg elem2;
	t_arg elem3;
	
	elem1.res ="first";
	elem1.next = &elem2;
	elem2.res = "second";
	elem2.next = &elem3;
	elem3.res = "trois";
	elem3.next = 0;
	lst = &elem1;
	aff_lst(&lst);
	printf("on ajoute\n");
	add_c(&lst, arg_newc('o'));
	printf("\n");
	aff_lst(&lst);
	return (0);
}

