/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:29:54 by ariard            #+#    #+#             */
/*   Updated: 2017/03/22 21:54:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_sstrstr(char **sstr, char *find)
{
	int		size;

	if (!sstr)
		return (NULL);
	size = ft_strlen(find);
	while ((*sstr))
	{
		if (ft_strncmp(*sstr, find, size) == 0)
			return (*sstr);
		sstr++;
	}
	return (NULL);
}
