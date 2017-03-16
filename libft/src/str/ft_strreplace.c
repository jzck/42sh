/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:50:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/12 13:59:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char **str, char *start, char *end, char *new)
{
	char	*out;

	out = ft_strnew(ft_strlen(*str) - (end - start) + ft_strlen(new) + 1);
	ft_strncpy(out, *str, start - *str);
	ft_strcat(out, new);
	ft_strcat(out, end + 1);
	ft_strdel(str);
	*str = out;
	return (out);
}
