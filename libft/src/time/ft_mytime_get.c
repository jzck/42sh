/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstrtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:34:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:42:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mytime	*ft_mytime_get(time_t epoch)
{
	char		*date;
	t_mytime	*time;

	time = (t_mytime*)ft_malloc(sizeof(*time));
	date = ctime(&epoch);
	date[ft_strlen(date) - 1] = 0;
	time->year = ft_isdigit(date[20]) ?
		ft_strsub(date, 20, 4) : ft_strsub(date, 24, 5);
	time->month = ft_strsub(date, 4, 3);
	time->day = ft_strsub(date, 8, 2);
	time->hour = ft_strsub(date, 11, 2);
	time->min = ft_strsub(date, 14, 2);
	time->sec = ft_strsub(date, 17, 2);
	return (time);
}
