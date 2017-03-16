/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:03:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 14:28:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstradd(char **sstr, char *new)
{
	int		size;
	char	**newlist;

	size = 0;
	if (sstr)
		while (sstr[size])
			size++;
	if (!(newlist = (char **)ft_memalloc(sizeof(char *) * (size + 2))))
		return (NULL);
	if (sstr)
		ft_memcpy(newlist, sstr, sizeof(char*) * size);
	newlist[size] = ft_strdup(new);
	newlist[size + 1] = NULL;
	free(sstr);
	return (newlist);
}
