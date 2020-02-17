/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:57:44 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/17 19:27:48 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	int				is_convers;
	int				alig;
	int				zero;
	int				width;
	char			prec;
	char			type;
	char			**str;
	char			*res;
	struct s_arg	*next;
}				t_arg;

int				parsing(const char *s, t_arg **lst);
int				ft_printf(const char *format, ...);
void			aff_lst(t_arg **lst);
void				add_c(t_arg **lst, t_arg *new);
t_arg			*arg_newc(char c);
#endif
