/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:29:02 by jperez-r          #+#    #+#             */
/*   Updated: 2020/12/13 17:42:35 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**   Función para evoluar las flags
*/

void	find_flag(t_oprint *op, char **src)
{
	while (**src == 45 || **src == 48 || **src == 32 || **src == 43
		|| **src == 35)
	{
		if (**src == 48 && op->minzero != 1)
			op->minzero = 0;
		else if (**src == 45)
			op->minzero = 1;
		else if (op->spasign != 2 && **src == 32)
			op->spasign = 1;
		else if (**src == 43)
			op->spasign = 2;
		else if (**src == 35)
			op->tag = 1;
		(*src)++;
	}
}

/*
**   Función para calcular el width y la precisión
*/

int		get_num(t_oprint *op, char **src)
{
	int	num;

	num = 0;
	if (**src == '*')
	{
		num = va_arg(op->lis, int);
		if (num < 0 && !op->dot)
		{
			num *= -1;
			op->minzero = 1;
		}
		(*src)++;
	}
	else
	{
		while (ft_isdigit(**src) == 1)
		{
			num *= 10;
			num += **src - 48;
			(*src)++;
		}
	}
	return (num);
}

/*
**   Función para evaluar el tipo
*/

void	find_type(t_oprint *op, char **src)
{
	if (**src == 'c' || **src == '%')
		print_c(op, **src);
	else if (**src == 's')
		print_s(op);
	else
	{
		if (op->minzero == 0 && op->dot && op->pre >= 0)
			op->minzero = -1;
		if (**src == 'p')
			print_p(op, (long)va_arg(op->lis, void *));
		else if (**src == 'd' || **src == 'i')
			print_diu(op, va_arg(op->lis, int), op->spasign);
		else if (**src == 'u')
			print_diu(op, va_arg(op->lis, unsigned int), 0);
		else if (**src == 'x' || **src == 'X')
			print_x(op, va_arg(op->lis, unsigned int), **src);
	}
}

/*
** Función para comprobar qué hay tras el porcentaje
*/

void	check_flags(t_oprint *op, char **src)
{
	(*src)++;
	initialize_struct(op);
	find_flag(op, src);
	op->wid = get_num(op, src);
	if (**src == '.')
	{
		(*src)++;
		op->dot = 1;
		op->pre = get_num(op, src);
	}
	find_type(op, src);
	if (!**src)
		(*src)--;
}

int		ft_printf(const char *format, ...)
{
	int			size;
	t_oprint	op;
	char		*src;

	if (!format)
		return (0);
	src = (char *)format;
	va_start(op.lis, format);
	size = 0;
	initialize_struct(&op);
	while (*src)
	{
		if (*src == '%' && *(src + 1))
			check_flags(&op, &src);
		else
		{
			ft_putchar_fd(*src, 1);
			op.size = 1;
		}
		size += op.size;
		src++;
	}
	va_end(op.lis);
	return (size);
}
