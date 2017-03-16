/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:48:35 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 16:28:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*a;

	a = (char *)big;
	i = 0;
	if (!*little)
		return (a);
	while (a[i])
	{
		j = 0;
		while (a[i + j] == little[j])
		{
			j++;
			if (!little[j])
				return (a + i);
		}
		i++;
	}
	return (NULL);
}
