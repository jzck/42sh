/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_validate_conv.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:53:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 16:53:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fmt_validate_mod(t_fmt *fmt)
{
	if (fmt->conversion == 's' || fmt->conversion == 'c')
		if (fmt->modifier[0] && ft_strcmp(fmt->modifier, "l"))
			ft_fmt_error_mod_conv(fmt->modifier, fmt->conversion);
}
