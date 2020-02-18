/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:57:44 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 11:58:40 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_arg
{
	int				is_convers; // -1 : erreur de conv, 0 char a print, 1 conversion
	int				alig;
	int				zero;
	int				width; // width > 0 c'est la taille sinon c'est *a
	int				prec; // prec > 0 c'est si -1 c est * 
	char			type; // cspdiuxX
	char			*res;
	struct s_arg	*next;
}				t_arg;

t_arg *init_arg();
void aff_arg(t_arg *arg);
t_arg			*check_conv(char *str);
int				parsing(const char *s, t_arg **lst);
int				ft_printf(const char *format, ...);
void			aff_lst(t_arg **lst);
void			add_c(t_arg **lst, t_arg *new);
t_arg			*arg_newc(char c);

int check_alig(char *str, t_arg *arg);
int check_zero(char *str, t_arg *arg);
#endif
