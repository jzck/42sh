/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:58:06 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 17:03:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sstrcat(char **sstr, char sep)
{
	int		len;
	int		i;
	char	*out;

	i = 0;
	len = 0;
	if (!sstr)
		return (NULL);
	while (sstr[i])
		len += ft_strlen(sstr[i++]);
	if (!(out = ft_strnew(sizeof(char) * (len + i + 1))))
		return (NULL);
	ft_strcpy(out, sstr[0]);
	i = 1;
	while (sstr[i])
	{
		ft_strcat(out, (char[]){sep, 0});
		ft_strcat(out, sstr[i++]);
	}
	return (out);
}
