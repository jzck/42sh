/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:08:10 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:10:35 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(unsigned int n, int base)
{
	size_t	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char			*ft_uitoa_base(unsigned int nbr, char *base)
{
	int		i;
	int		base_size;
	char	*str;

	i = 0;
	base_size = ft_strlen(base);
	str = ft_strnew(ft_size(nbr, base_size) + 1);
	if (nbr == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (nbr)
	{
		str[i++] = base[nbr % base_size];
		nbr = nbr / base_size;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
