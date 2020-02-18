/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:57:44 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/18 14:14:11 by lnadal-s         ###   ########.fr       */
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

int				process_S(const char *s, t_arg **lst);
int				get_convlst(const char *format, t_arg **lst);

// <--------- LINKED LIST UTILS --------->
void			aff_lst(t_arg **lst);
void			add_c(t_arg **lst, t_arg *new);
t_arg			*arg_newc(char c);
t_arg 			*init_arg();
void 			aff_arg(t_arg *arg);
int get_val(const char* format);

// <--------- CHECK FORMAT --------->
int				check_conv(const char *str, t_arg **lst);
int 			check_alig(const char *str, t_arg *arg);
int 			check_zero(const char *str, t_arg *arg);
int 			check_width(const char *str, t_arg *arg);
int 			check_prec(const char *str, t_arg *arg);
int 			check_flag(const char c, t_arg *arg);
int 			is_flag(char c);
#endif
