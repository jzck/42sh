/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:29:54 by ariard            #+#    #+#             */
/*   Updated: 2017/03/07 12:44:17 by ariard           ###   ########.fr       */
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
		DG("size : %d", size);
		DG("sstr : %s", *sstr);
		DG("find : %s", find);
		if (ft_strncmp(*sstr, find, size) == 0)
			return (*sstr);
		sstr++;
	}
	return (NULL);
}
