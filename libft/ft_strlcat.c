/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:31:21 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/13 13:28:37 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dsize;
	size_t	srcsize;

	i = 0;
	dsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (dstsize < dsize)
		return (srcsize + dstsize);
	if (dstsize == 0)
		return (srcsize);
	j = dsize;
	while (j < dstsize - 1 && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (srcsize + dsize);
}
