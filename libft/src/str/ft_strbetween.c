/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbetween.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:26:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/12 14:54:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbetween(char *start, char *end)
{
	char	*out;

	out = ft_strnew(end - start + 1);
	ft_strncpy(out, start, end - start);
	return (out);
}
