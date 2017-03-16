/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:46:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/09 19:02:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatf(char *s1, const char *s2)
{
	char	buf[ft_strlen(s2)];

	ft_strcpy(buf, s1);
	ft_strcpy(s1, s2);
	ft_strcat(s1, buf);
	return (s1);
}
