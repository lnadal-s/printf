/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_check_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:57:21 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 14:56:50 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char *str = "%123sbonjour %%  merce---0123.*p Xet saluuut %-0*.2147483647d %c oui %*d %.x";
	//char *str = " % ";
	
	
	printf("v:%d\n", get_val(str));
}
