/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:10:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 15:23:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_flags(char *str, int *i, char *flags, int neg)
{
	if (neg)
		str[(*i)++] = '-';
	else if (ft_strchr(flags, '+'))
		str[(*i)++] = '+';
	else if (ft_strchr(flags, ' '))
		str[(*i)++] = ' ';
	return (str);
}

char			*ft_lltoa_base(long long nbr, char *base, char *flags)
{
	int		i;
	int		neg;
	int		base_size;
	char	*str;

	i = 0;
	base_size = ft_strlen(base);
	str = ft_strnew(ft_lllen_base(nbr, base_size) + 1);
	neg = FT_NEG(nbr);
	if (nbr == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (nbr)
	{
		str[i++] = base[FT_ABS(nbr % base_size)];
		nbr = nbr / base_size;
	}
	str = ft_flags(str, &i, flags, neg);
	str[i] = 0;
	ft_strrev(str);
	return (str);
}
