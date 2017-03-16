/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 13:14:30 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pad_right(char *str, t_fmt *fmt)
{
	if (ft_strchr(fmt->flags, '#'))
		(fmt->conv.sharp_func)(str, fmt);
	while ((int)ft_strlen(str) < fmt->width)
		ft_strcat(str, " ");
}

void	ft_pad_left(char *str, t_fmt *fmt)
{
	char	sign;

	sign = 0;
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		sign = str[0];
		str++;
	}
	if (ft_strchr(fmt->flags, '0'))
		while ((int)ft_strlen(str) < fmt->width - (sign ? 1 : 0))
			ft_strcatf(str, "0");
	if (sign)
		str--;
	if (ft_strchr(fmt->flags, '#'))
		(fmt->conv.sharp_func)(str, fmt);
	while ((int)ft_strlen(str) < fmt->width)
		ft_strcatf(str, " ");
}
