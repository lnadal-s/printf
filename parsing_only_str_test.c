/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_only_str_test.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:15:03 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/17 19:27:50 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char *str = "et merc%e la zone";
	t_arg **lst;
	
	if (!(lst = (t_arg**)malloc(sizeof(t_arg *))))
		return 0;
	*lst = 0;
	parsing(str, lst);
	aff_lst(lst);
}
