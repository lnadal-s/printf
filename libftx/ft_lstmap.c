/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:24:51 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/10/28 11:41:51 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*ptr;
	t_list		*newlst;
	t_list		*elem;
	t_list		*newelem;

	newlst = ft_lstnew(f(lst->content));
	elem = newlst;
	ptr = lst->next;
	while (ptr)
	{
		if (!(newelem = ft_lstnew(f(ptr->content))))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		elem->next = newelem;
		elem = elem->next;
		ptr = ptr->next;
	}
	return (newlst);
}
