/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:08:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/29 14:48:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *s, const char *delim)
{
	static char		*lasts = NULL;
	int				ch;

	if (!s)
	{
		if (!lasts)
			return (NULL);
		s = lasts;
	}
	if ((ch = *s++) == 0)
		return (0);
	while (ft_strchr(delim, ch))
		if ((ch = *s++) == 0)
			return (0);
	--s;
	lasts = s + ft_strcspn(s, delim);
	if (*lasts != 0)
		*lasts++ = 0;
	return (s);
}
