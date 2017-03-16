/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:16:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/19 05:50:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strappend(char **dst, char *src)
{
	char	*out;

	if (!(out = ft_strjoin(*dst, src)))
		return (-1);
	ft_strdel(dst);
	*dst = out;
	return (0);
}
