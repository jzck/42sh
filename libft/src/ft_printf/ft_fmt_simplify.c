/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fmt_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 16:53:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fmt_simplify(t_fmt *fmt)
{
	char	hashtag;

	hashtag = '#';
	if (fmt->conversion == 'p')
	{
		fmt->conversion = 'x';
		if (!ft_strchr(fmt->flags, '#'))
			ft_strncat(fmt->flags, &hashtag, 1);
	}
	if (ft_strchr("DOUCS", fmt->conversion))
	{
		fmt->conversion += 32;
		ft_strcpy(fmt->modifier, "l");
	}
}
