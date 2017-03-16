/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:28 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 14:58:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*out;

	size = ft_strlen(s);
	out = (char *)malloc(sizeof(char) * (size + 1));
	if (out == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		out[i] = (*f)(i, s[i]);
	return (out);
}
