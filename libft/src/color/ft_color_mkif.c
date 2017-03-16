/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_mk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:35:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 12:17:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color_mkif(t_color *color, int cond, char fg[7], char bg[7])
{
	if (cond)
		ft_color_mk(color, fg, bg);
}
