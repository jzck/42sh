/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 13:11:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*out;
	char	*last;

	while (*s && FT_WS(*s))
		s++;
	out = ft_strdup(s);
	last = out + ft_strlen(out) - 1;
	while (last > out && FT_WS(*last))
		*last-- = 0;
	return (out);
}
