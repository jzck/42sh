/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:01:15 by ariard            #+#    #+#             */
/*   Updated: 2017/03/07 11:24:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdupchr(const char *str, char c)
{
	char	*new;

	if (!str || !(new = ft_memalloc(sizeof(*new) * (ft_strlenchr(str, c) + 1))))
		return (NULL);
	ft_strchrcpy(new, str, c);
	return (new);
}
