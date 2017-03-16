/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:37:12 by ariard            #+#    #+#             */
/*   Updated: 2017/03/07 12:41:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strduptr(char *str, int (*is)(int c))
{
	char	*new;
	char	*tmp;

	new = ft_memalloc(sizeof(char *) * ft_strlen(str) + 1);
	tmp = new;
	while (*str && (is)((int)*str))
		*new++ = *str++;
	*new = 0;
	return (tmp);
}
