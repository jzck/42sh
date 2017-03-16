/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 23:31:20 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 18:03:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if (str[i] < 32 || str[i] > 126)
			return (0);
		j = 0;
		while (j < i)
		{
			if (str[j] == str[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

static int		get_pos(char c, char *str)
{
	int		i;

	i = 0;
	while (c != str[i] && str[i])
		i++;
	return (i);
}

static int		ft_check_str(char *str, char *base, int base_size)
{
	while (*str)
	{
		if (!(get_pos(*str, base) < base_size || *str == '-' || *str == '+'))
			return (0);
		str++;
	}
	return (1);
}

char			*ft_convert_base(
		char *str, char *base_from, char *base_to, char *flags)
{
	int		base_size;
	int		res;
	int		sign;

	base_size = get_size(base_from);
	res = 0;
	sign = 1;
	if (!ft_check_str(str, base_from, base_size))
		return (ft_itoa_base(0, "0", flags));
	if (base_size > 1)
	{
		if (*str == '-' || *str == '+')
		{
			if (get_pos(*(str + 1), base_from) < base_size)
				sign = (*str == '+') ? 1 : -1;
			else
				return (ft_itoa_base(0, "0", flags));
			str++;
		}
		while (get_pos(*str, base_from) < base_size)
			res = res * base_size + sign * get_pos(*str++, base_from);
	}
	return (ft_itoa_base(res, base_to, flags));
}
