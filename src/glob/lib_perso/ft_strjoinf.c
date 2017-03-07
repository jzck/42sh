/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:33:24 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:19:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
