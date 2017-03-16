/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:53:46 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 11:55:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color_set(t_color color)
{
	char	out[20];

	ft_strcpy(out, color.fg);
	ft_strcat(out, color.bg);
	ft_putstr(out);
}
