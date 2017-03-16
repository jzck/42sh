/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:28 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 17:41:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*a;
	size_t	i;

	i = -1;
	a = (unsigned char *)s;
	while (++i < n)
	{
		if (*(unsigned char *)a == (unsigned char)c)
			return (a);
		a++;
	}
	return (NULL);
}
