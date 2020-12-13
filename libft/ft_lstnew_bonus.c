/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 06:13:40 by jperez-r          #+#    #+#             */
/*   Updated: 2019/12/19 10:06:28 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content)
{
	t_list	*lis;

	if (!(lis = malloc(sizeof(*lis))))
		return (0);
	lis->content = (void *)content;
	lis->next = NULL;
	return (lis);
}
