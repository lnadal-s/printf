/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:18:33 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/31 11:40:32 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *ptr;
	t_list *tmp;

	if (lst)
	{
		ptr = *lst;
		while (ptr)
		{
			del(ptr->content);
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
	}
}
