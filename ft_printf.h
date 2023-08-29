/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:29:43 by jperez-r          #+#    #+#             */
/*   Updated: 2023/08/09 23:14:54 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct oprint
{
	int		wid;
	int		dot;
	int		pre;
	int		minzero;
	int		size;
	int		len;
	int		neg;
	int		spasign;
	int		tag;
	char	*hex;
	va_list	lis;
}			t_oprint;

void		initialize_struct(t_oprint *op);
char		*x_up(char *s);
long		is_negative(t_oprint *op, long nb);
void		is_tag(t_oprint *op, char t);
void		put_sign(t_oprint *op);

void		set_size(t_oprint *op);
void		put_width(t_oprint *op);
void		put_precision(t_oprint *op);

void		print_c(t_oprint *op, char t);
void		print_s(t_oprint *op);
void		print_p(t_oprint *op, void *nbr);
void		print_diu(t_oprint *op, long nbr, int spa);
void		print_x(t_oprint *op, long nbr, char t);

void		find_flag(t_oprint *op, char **src);
int			get_num(t_oprint *op, char **src);
void		find_type(t_oprint *op, char **src);
void		check_flags(t_oprint *op, char **src);
int			ft_printf(const char *format, ...);

#endif
