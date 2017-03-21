/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:04:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 17:52:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sstrdel(char **sstr, int index)
{
	int		i;

	i = index;
	while (sstr[i])
	{
		sstr[i] = sstr[i + 1];
		i++;
	}
	ft_strdel(sstr + index);
}
