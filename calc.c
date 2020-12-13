/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:25:52 by jperez-r          #+#    #+#             */
/*   Updated: 2020/12/13 15:28:36 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Cálculo del size y reasiganación de tamaños de width y precision
*/

void	set_size(t_oprint *op)
{
	int	tmp;

	if (op->len >= op->pre)
	{
		tmp = op->len;
		if (op->pre > 0 || op->pre < -2)
			op->pre = -1;
	}
	else
	{
		tmp = op->pre;
		op->pre -= op->len;
	}
	if (op->wid > tmp)
	{
		op->size += op->wid;
		op->wid -= tmp;
	}
	else
	{
		op->wid = 0;
		if (op->minzero == 0)
			op->minzero--;
		op->size += tmp;
	}
}

/*
**	Escritura de width, 0 o espacio
*/

void	put_width(t_oprint *op)
{
	while (op->wid > 0)
	{
		if (op->minzero == 0)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		op->wid--;
	}
	op->wid++;
}

/*
**	Escritura de precisión para numéricos
*/

void	put_precision(t_oprint *op)
{
	while (op->pre > 0)
	{
		ft_putchar_fd('0', 1);
		op->pre--;
	}
	op->pre--;
}
