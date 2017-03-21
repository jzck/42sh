/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:31:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:42:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_signed_conversion(t_fmt *fmt, va_list ap)
{
	static char	base10[] = "0123456789";
	long long	arg;

	arg = va_arg(ap, int);
	(void)fmt;
	return (ft_lltoa_base(arg, base10, fmt->flags));
}

char	*ft_unsigned_conversion(t_fmt *fmt, va_list ap)
{
	unsigned int		uiarg;
	unsigned long long	ullarg;
	int					i;

	i = 0;
	while (fmt->conversion != g_convs[i].id)
		i++;
	if (!*fmt->modifier
			|| ft_strequ(fmt->modifier, "hh")
			|| ft_strequ(fmt->modifier, "h")
			|| ft_strequ(fmt->modifier, "z"))
	{
		uiarg = va_arg(ap, int);
		return (ft_uitoa_base(uiarg, g_convs[i].base));
	}
	ullarg = va_arg(ap, long long);
	return (ft_ulltoa_base(ullarg, g_convs[i].base));
}

char	*ft_char_conversion(t_fmt *fmt, va_list ap)
{
	char	*ret;

	(void)fmt;
	ret = (char *)ft_malloc(sizeof(char) + 1);
	ret[0] = (char)va_arg(ap, int);
	ret[1] = '\0';
	return (ret);
}

char	*ft_str_conversion(t_fmt *fmt, va_list ap)
{
	char	*ret;

	(void)fmt;
	ret = va_arg(ap, char *);
	if (ret == NULL)
		return (ft_strdup("NULL"));
	ret = ft_strdup(ret);
	if (fmt->precision && fmt->precision < (int)ft_strlen(ret))
		ret[fmt->precision] = '\0';
	return (ret);
}
