/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mytime_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:45:29 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 13:11:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mytime_free(t_mytime **time)
{
	ft_strdel(&(*time)->year);
	ft_strdel(&(*time)->month);
	ft_strdel(&(*time)->day);
	ft_strdel(&(*time)->hour);
	ft_strdel(&(*time)->min);
	ft_strdel(&(*time)->sec);
	ft_memdel((void **)time);
}
