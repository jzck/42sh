/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:29:54 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:18:08 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
