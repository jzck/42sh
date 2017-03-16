/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/06 15:39:36 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c1;
	char	*c2;

	if (n == 0 || dst == src)
		return (dst);
	c1 = (char *)dst;
	c2 = (char *)src;
	while (--n)
		*c1++ = *c2++;
	*c1 = *c2;
	return (dst);
}
