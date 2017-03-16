/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:21:57 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/21 18:21:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *str, char c, int n)
{
	char	tmp[ft_strlen(str)];
	char	*out;

	ft_strcpy(tmp, str + n);
	str[n] = 0;
	out = ft_str3join(str, (char[]){c, 0}, tmp);
	return (out);
}
