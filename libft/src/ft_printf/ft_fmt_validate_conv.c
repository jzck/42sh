/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_validate_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:55:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 16:55:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fmt_validate_conv(t_fmt *fmt)
{
	if (!ft_strchr(ALL_CONVERSIONS, fmt->conversion))
	{
		if (fmt->conversion != '%')
			ft_fmt_error_conv(fmt->conversion);
		return (1);
	}
	return (0);
}
