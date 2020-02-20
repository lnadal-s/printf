/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:19:20 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/28 12:05:44 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = *alst;
	if (!(alst))
		return ;
	else if (!(*alst))
		*alst = new;
	else
	{
		if (ptr->next)
			while (ptr->next)
				ptr = ptr->next;
		ptr->next = new;
		new->next = 0;
	}
}
