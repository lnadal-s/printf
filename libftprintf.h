/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:57:44 by lnadal-s          #+#    #+#             */
/*   Updated: 2020/02/20 11:27:21 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>
typedef struct	s_arg
{
	int				is_convers; // -1 : erreur de conv, 0 char a print, 1 conversion
	int				alig;
	int				zero;
	int				width; // width > 0 c'est la taille sinon c'est *a
	int				prec; // prec > 0 c'est si -1 c est * 
	int				is_prec;
	char			type; // cspdiuxX
	char			*res;
	int				len;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_print
{
	va_list ap;
	t_arg **lst;
}				t_print;

// <--------- TRAITEMENT ARGS --------->
int process(t_print *tp);
int process_c(t_print *tp, t_arg *arg);
int process_str(t_print *tp, t_arg *ptr);
int process_dec(t_print *tp, t_arg *arg);

// <--------- TRAITEMENT FORMAT --------->
int				acquisition(const char *format, t_arg **lst);

// <--------- PRINTING --------->;
int				printing(t_arg **lst);

// <--------- LINKED LIST UTILS --------->
void			aff_lst(t_arg **lst);
void			add_c(t_arg **lst, t_arg *new);
t_arg			*arg_newc(char c);
t_arg 			*init_arg();
void 			aff_arg(t_arg *arg);
int				ft_printf(const char* format, ...);
size_t			len_ll(t_arg **lst);
int				init_lst(t_arg **lst);

	// <--------- CHECK FORMAT --------->
int 			check_alig(const char *str, t_arg *arg);
int 			check_zero(const char *str, t_arg *arg);
int 			check_width(const char *str, t_arg *arg);
int 			check_prec(const char *str, t_arg *arg);
int 			check_flag(const char c, t_arg *arg);
int				is_flag(char c);

// <--------- UTILS --------->
char			*alloc_char(char c, int size);
int				get_star(t_print *tp, t_arg *arg);

// <--------- SPECIFIC CASE --------->
int				alig_zero(t_arg *arg);
void			check_neg_width(t_arg *arg);

// <--------- CLEAR --------->
int				clear_sp(t_print *tp);
void	clear_s_arg(t_arg **lst);
void	del_one(t_arg *arg);
#endif
