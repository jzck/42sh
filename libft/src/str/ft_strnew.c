/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:58:34 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 16:37:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*addr;
	size_t	i;

	addr = (char *)malloc(size + 1);
	if (addr == NULL)
		return (NULL);
	i = -1;
	while (++i <= size)
		addr[i] = '\0';
	return (addr);
}
