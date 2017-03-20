/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:27 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 15:53:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_convs[] =
{
	{'d', "0- +", "0123456789", &ft_signed_conversion, NULL},
	{'i', "0- +", "0123456789", &ft_signed_conversion, NULL},
	{'u', "0-", "0123456789", &ft_unsigned_conversion, NULL},
	{'o', "#0-", "01234567", &ft_unsigned_conversion, &ft_pad_sharp_o},
	{'x', "#0-", "0123456789abcdef", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'X', "#0-", "0123456789ABCDEF", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'b', "#0-", "01", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'s', "-", "", &ft_str_conversion, NULL},
	{'c', "-", "", &ft_char_conversion, NULL},
};

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vdprintf(1, format, ap));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vdprintf(fd, format, ap));
}

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vasprintf(ret, format, ap));
}
