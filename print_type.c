/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:29:32 by jperez-r          #+#    #+#             */
/*   Updated: 2020/12/13 15:39:05 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Gestor de tipos para imprimir
*/

void	print_c(t_oprint *op, char t)
{
	op->len = 1;
	op->pre = -1;
	set_size(op);
	if (op->wid > 0 && op->minzero != 1)
		put_width(op);
	if (t == 37)
		write(1, &t, 1);
	else
		ft_putchar_fd(va_arg(op->lis, int), 1);
	if (op->wid > 0 && op->minzero == 1)
		put_width(op);
}

void	print_s(t_oprint *op)
{
	char	*s;

	s = va_arg(op->lis, char *);
	if (s == NULL)
		s = "(null)";
	op->len = ft_strlen(s);
	if (op->len > op->pre && op->pre >= 0)
	{
		op->len = op->pre;
		if (op->len == 0)
			s = 0;
		else
			s = ft_substr(s, 0, op->len);
		op->pre = -2;
	}
	if (op->pre != -2)
		op->pre = -1;
	set_size(op);
	if (op->wid >= 1 && op->minzero != 1)
		put_width(op);
	ft_putstr_fd(s, 1);
	if (op->pre == -2)
		free(s);
	if (op->wid >= 1 && op->minzero == 1)
		put_width(op);
}

void	print_p(t_oprint *op, long nbr)
{
	op->hex = ft_itoa_base(nbr, 16);
	if (nbr == 0)
		op->hex = ft_strdup("0");
	op->len = ft_strlen(op->hex);
	op->wid -= 2;
	if (op->pre == 0 && *op->hex == '0' && op->wid)
		op->wid++;
	set_size(op);
	op->size += 2;
	if (op->minzero == 0)
		ft_putstr_fd("0x", 1);
	if (op->wid > 0 && op->minzero != 1)
		put_width(op);
	if (op->minzero != 0)
		ft_putstr_fd("0x", 1);
	if (op->pre > 0)
		put_precision(op);
	if (op->pre == 0 && *op->hex == '0')
		op->size--;
	else
		ft_putstr_fd(op->hex, 1);
	free(op->hex);
	if (op->wid > 0 && op->minzero == 1)
		put_width(op);
}

/*
**	En la función para hacer los numéricos están los flag espacio y +
*/

void	print_diu(t_oprint *op, long nbr, int spasign)
{
	op->len = ft_intlen(nbr);
	nbr = is_negative(op, nbr);
	if (!op->neg && spasign > 0)
		op->size++;
	if (spasign == 1 && !op->neg)
		ft_putchar_fd(32, 1);
	if (spasign > 0 && !op->neg)
		op->wid--;
	if (op->pre == 0 && nbr == 0 && op->wid)
		op->wid++;
	if (!op->minzero)
		put_sign(op);
	set_size(op);
	if (op->wid > 0 && op->minzero != 1)
		put_width(op);
	if (op->minzero)
		put_sign(op);
	if (op->pre > 0)
		put_precision(op);
	if (op->pre == 0 && nbr == 0)
		op->size--;
	else
		ft_putnbr_fd(nbr, 1);
	if (op->wid > 0 && op->minzero == 1)
		put_width(op);
}

/*
**	En el tipo x se encuentra el flag #
*/

void	print_x(t_oprint *op, long nbr, char t)
{
	if (nbr == 0)
		op->hex = ft_strdup("0");
	else
		op->hex = ft_itoa_base(nbr, 16);
	op->len = ft_strlen(op->hex);
	if (op->pre == 0 && *op->hex == '0' && op->wid)
		op->wid++;
	set_size(op);
	if (op->tag)
		is_tag(op, t);
	if (op->wid > 0 && op->minzero != 1)
		put_width(op);
	is_tag(op, t);
	if (op->pre > 0)
		put_precision(op);
	if (op->pre == 0 && *op->hex == '0')
		op->size--;
	else if (t == 'x')
		ft_putstr_fd(op->hex, 1);
	else
		ft_putstr_fd(x_up(op->hex), 1);
	free(op->hex);
	if (op->wid > 0 && op->minzero == 1)
		put_width(op);
}
