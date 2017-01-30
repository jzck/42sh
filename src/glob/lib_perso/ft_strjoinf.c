/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:33:24 by wescande          #+#    #+#             */
/*   Updated: 2017/01/24 16:53:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

char	*ft_strjoinf(char *s1, char *s2, int state)
{
	char	*ans;

	ans = ft_strjoin((const char *)s1, (const char *)s2);
	if (state == 1 || state == 3)
		ft_strdel(&s1);
	if (state == 2 || state == 3)
		ft_strdel(&s2);
	return (ans);
}
