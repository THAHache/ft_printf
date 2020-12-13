/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 15:29:58 by jperez-r          #+#    #+#             */
/*   Updated: 2020/12/13 15:30:03 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_struct(t_oprint *op)
{
	op->wid = 0;
	op->dot = 0;
	op->pre = -1;
	op->minzero = -1;
	op->hex = "\0";
	op->size = 0;
	op->len = 0;
	op->neg = 0;
	op->spasign = 0;
	op->tag = 0;
}

/*
**	Función para volver mayus la X
*/

char	*x_up(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}

/*
**	Comprobación de números negativos
*/

long	is_negative(t_oprint *op, long nb)
{
	if (nb < 0)
	{
		nb *= -1;
		op->neg = 1;
		if (op->pre > 0)
			op->pre++;
	}
	return (nb);
}

/*
**	Comprobar el flag #
*/

void	is_tag(t_oprint *op, char t)
{
	if (op->tag == 2)
	{
		if (op->wid < 0)
			op->size += 2;
		if (t == 'x')
			ft_putstr_fd("0x", 1);
		else
			ft_putstr_fd("0X", 1);
	}
	else if (op->tag && *op->hex != '0')
	{
		op->wid -= 2;
		if (op->minzero >= 0 && op->wid >= op->pre)
		{
			if (t == 'x')
				ft_putstr_fd("0x", 1);
			else
				ft_putstr_fd("0X", 1);
			op->tag = 0;
		}
		else
			op->tag = 2;
	}
}

/*
**	Escritura del símbolo
*/

void	put_sign(t_oprint *op)
{
	if (op->spasign == 2 && !op->neg)
		ft_putchar_fd('+', 1);
	else if (op->neg == 1)
	{
		op->neg = 0;
		ft_putchar_fd('-', 1);
	}
}
