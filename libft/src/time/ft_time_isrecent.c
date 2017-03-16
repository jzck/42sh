/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_isrecent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:01:04 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 11:43:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_time_isrecent(time_t event)
{
	time_t	now;

	now = time(&now);
	if (now - event >= 0 && now - event <= 6 * 365 / 12 * 24 * 60 * 60)
		return (1);
	else
		return (0);
}
