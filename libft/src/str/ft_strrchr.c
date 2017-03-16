/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:38 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 15:08:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		i;

	a = (char *)s;
	i = ft_strlen(a);
	while (i >= 0)
	{
		if (a[i] == (char)c)
			return (a + i);
		i--;
	}
	return (NULL);
}
