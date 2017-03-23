/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:04:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/23 18:31:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sstrdel(char **sstr, int index)
{
	int		i;

	i = index;
	free(sstr[index]);
	while (sstr[i])
	{
		sstr[i] = sstr[i + 1];
		i++;
	}
}
