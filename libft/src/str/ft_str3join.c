/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:03:26 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 16:07:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	join = ft_strnew(size + 1);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	ft_strcat(join, s3);
	return (join);
}
