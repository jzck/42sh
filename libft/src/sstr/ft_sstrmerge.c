/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrmerge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:40:50 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 18:05:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstrmerge(char **s1, char **s2)
{
	char	**out;

	out = ft_sstrdup(s1);
	if (!s2)
		return (out);
	while (*s2)
	{
		out = ft_sstradd(out, *s2);
		s2++;
	}
	return (out);
}
