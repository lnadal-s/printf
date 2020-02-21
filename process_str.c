/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:43:58 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/21 12:17:40 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_str(char *str, t_arg *arg)
{
	int		size;
	char	*dst;
	char	*w;

	size = (int)ft_strlen(str);
	if (arg->is_prec == 1)
		size = arg->prec < size ? arg->prec : size;
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return ;
	if (arg->width > size && !(w = alloc_char(' ', arg->width - size)))
	{
		free(dst);
		return ;
	}
	else if (arg->width <= size)
		w = ft_strdup("");
	ft_strlcpy(dst, str, size + 1);
	if (arg->alig == 0)
		arg->res = ft_strjoin(w, dst);
	else
		arg->res = ft_strjoin(dst, w);
	free(w);
	free(dst);
}

int		process_str(t_print *tp, t_arg *arg)
{
	char *str;

	if (alig_zero(arg) == -1)
		return (-1);
	if (arg->zero == 1)
		return (-1);
	if (get_star(tp, arg) < 0)
		arg->prec = 0;
	if (!(str = va_arg(tp->ap, char *)))
		str = ft_strdup("(null)");
	get_str(str, arg);
	arg->len = ft_strlen(arg->res);
	return (1);
}
