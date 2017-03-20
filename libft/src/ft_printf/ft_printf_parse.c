/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 15:55:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_parse_flags(t_fmt *fmt, char **format)
{
	int		i;
	char	*str;

	i = 0;
	str = *format;
	while (str[i])
	{
		if (ft_strchr(ALL_FLAGS, (int)str[i]))
		{
			if (!ft_strchr(fmt->flags, (int)str[i]))
				ft_strncat(fmt->flags, str + i, 1);
		}
		else
			break ;
		i++;
	}
	*format += i;
}

static void	ft_printf_parse_width(t_fmt *fmt, char **format, va_list ap)
{
	int		i;
	char	buf[10];
	char	*str;

	i = 0;
	str = *format;
	if (str[i] == '*')
	{
		i++;
		fmt->width = va_arg(ap, int);
	}
	else
	{
		ft_strcpy(buf, "0");
		while (ft_isdigit((int)(str[i])))
			ft_strncat(buf, str + i++, 1);
		fmt->width = ft_atoi(buf);
	}
	*format += i;
}

static void	ft_printf_parse_precision(t_fmt *fmt, char **format, va_list ap)
{
	int		i;
	char	buf[10];
	char	*str;

	i = 0;
	str = *format;
	if (str[i] == '.')
	{
		if (str[++i] == '*')
		{
			i++;
			fmt->precision = va_arg(ap, int);
		}
		else
		{
			ft_strcpy(buf, "0");
			while (ft_isdigit(str[i]))
				ft_strncat(buf, str + i++, 1);
			fmt->precision = ft_atoi(buf);
		}
	}
	*format += i;
}

static void	ft_printf_parse_modifiers(t_fmt *fmt, char **format)
{
	char	*str;

	str = *format;
	if (str[0] == 'h' && str[1] == 'h')
		ft_strcpy(fmt->modifier, "hh");
	else if (str[0] == 'h' && str[1] != 'h')
		ft_strcpy(fmt->modifier, "h");
	else if (str[0] == 'l' && str[1] == 'l')
		ft_strcpy(fmt->modifier, "ll");
	else if (str[0] == 'l' && str[1] != 'l')
		ft_strcpy(fmt->modifier, "l");
	else if (str[0] == 'j')
		ft_strcpy(fmt->modifier, "j");
	else if (str[0] == 'z')
		ft_strcpy(fmt->modifier, "z");
	else
		ft_strcpy(fmt->modifier, "");
	*format += ft_strlen(fmt->modifier);
}

t_fmt		*ft_printf_parse(char **format, va_list ap)
{
	t_fmt		*fmt;

	fmt = ft_fmt_init();
	ft_printf_parse_flags(fmt, format);
	ft_printf_parse_width(fmt, format, ap);
	ft_printf_parse_precision(fmt, format, ap);
	ft_printf_parse_modifiers(fmt, format);
	fmt->conversion = **format;
	(*format)++;
	ft_fmt_validate_mod(fmt);
	ft_fmt_validate_flags(fmt);
	ft_fmt_simplify(fmt);
	fmt->valid = ft_fmt_validate_conv(fmt) ? 0 : 1;
	return (fmt);
}
