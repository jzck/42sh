/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/02/02 14:22:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

void		ft_tabdel(char ***mytab)
{
	char	**erase;
	int		i;

	if (!mytab || !*mytab)
		return ;
	erase = *mytab;
	i = 0;
	while (erase[i])
	{
		ft_strdel(&erase[i]);
		++i;
	}
	free(*mytab);
	*mytab = NULL;
}
