/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 12:08:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		neg;

	i = 0;
	str = ft_strnew(ft_size(n) + 1);
	neg = FT_NEG(n) ? 1 : 0;
	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (n)
	{
		str[i++] = FT_ABS(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
