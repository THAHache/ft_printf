/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:06:42 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/19 05:01:48 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_toa(char *dst, long int n, int len)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		dst[i] = '-';
		n *= -1;
		len--;
		i++;
	}
	while (len > 0)
	{
		dst[i] = n / ft_pow(10, len) + 48;
		n %= ft_pow(10, len);
		len--;
		i++;
	}
	len = ft_intlen(n);
}

char		*ft_itoa(int n)
{
	size_t		len;
	char		*dst;
	long int	nb;

	len = ft_intlen(n);
	nb = n;
	if (!(dst = malloc(len + 1)))
		return (0);
	ft_toa(dst, nb, len);
	dst[len] = '\0';
	return (dst);
}
