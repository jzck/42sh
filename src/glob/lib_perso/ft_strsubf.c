/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:20:08 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:20:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strsubf(char *s, unsigned int start, size_t len, short int mode)
{
	char	*sptr;

	if (!s)
		return (NULL);
	sptr = ft_strsub(s, start, len);
	if (mode == 1)
		ft_strdel(&s);
	return (sptr);
}
