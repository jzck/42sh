/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_mk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:35:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 11:54:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color_mk(t_color *color, char fg[7], char bg[7])
{
	ft_strcpy(color->fg, fg);
	ft_strcpy(color->bg, bg);
}
