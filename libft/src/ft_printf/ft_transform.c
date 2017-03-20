/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 09:23:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

enum e_conversion =
{
	CONV_D,
	CONV_I,
	CONV_U,
	CONV_O,
	CONV_x,
	CONV_X,
	CONV_B,
	CONV_S,
	CONV_C,
};

char	*ft_transform(t_fmt *fmt, va_list ap)
{
	char	*ret;
	int		i;

	i = 0;
	while (fmt->conversion != g_convs[i].id)
		i++;
	fmt->conv = g_convs[i];
	ret = (*fmt->conv.converter)(fmt, ap);
	if (fmt->width > (int)ft_strlen(ret))
		ret = ft_realloc(ret, fmt->width + 5);
	else
		ret = ft_realloc(ret, ft_strlen(ret) + 3);
	if (ft_strchr(fmt->flags, '-'))
		ft_pad_right(ret, fmt);
	else
		ft_pad_left(ret, fmt);
	return (ret);
}
