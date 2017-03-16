/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:57:07 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 15:02:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size;
	size_t	j;

	size = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0' && j < n)
	{
		s1[size + j] = s2[j];
		j++;
	}
	s1[size + j] = '\0';
	return (s1);
}
