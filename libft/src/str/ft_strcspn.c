/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:55:33 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 16:00:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(char *s, const char *delim)
{
	char	*str;

	str = s;
	while (*str)
		if (ft_strchr(delim, *str))
			return (str - s);
		else
			str++;
	return (str - s);
}
