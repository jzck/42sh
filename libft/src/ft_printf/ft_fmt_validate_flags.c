/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_validate_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:53:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 15:19:35 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fmt_validate_flag_flag(t_fmt *fmt)
{
	char	*flag_ptr;

	if (ft_strchr(fmt->flags, '+') && (flag_ptr = ft_strchr(fmt->flags, ' ')))
	{
		ft_fmt_error_flag_flag(' ', '+');
		*flag_ptr = '.';
	}
	if (ft_strchr(fmt->flags, '-') && (flag_ptr = ft_strchr(fmt->flags, '0')))
	{
		ft_fmt_error_flag_flag('0', '-');
		*flag_ptr = '.';
	}
	if (fmt->precision && (flag_ptr = ft_strchr(fmt->flags, '0')))
		*flag_ptr = '.';
}

static void	ft_fmt_validate_flag_conv(t_fmt *fmt)
{
	char	*flag_ptr;
	char	flag;
	int		i;

	i = 0;
	flag_ptr = fmt->flags;
	while (fmt->conversion != g_convs[i].id)
		i++;
	while (*flag_ptr)
	{
		flag = *flag_ptr;
		if (!ft_strchr(g_convs[i].allowed_flags, flag))
		{
			ft_fmt_error_flag_conv(flag, fmt->conversion);
			if (flag == '#')
				*flag_ptr = '.';
		}
		flag_ptr++;
	}
}

void		ft_fmt_validate_flags(t_fmt *fmt)
{
	ft_fmt_validate_flag_conv(fmt);
	ft_fmt_validate_flag_flag(fmt);
}
