/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:00:21 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/18 21:29:35 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	if (!(s && f))
		return (NULL);
	if (!(dst = malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		dst[i] = (char)f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
