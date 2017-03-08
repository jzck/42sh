/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:06:19 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/07 16:02:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*g_hash[MAX_HASH] = {NULL};

int		ft_hash(t_process *p)
{
	if (!ft_is_hash(p))
		if (!ft_add_hash(p))
			return (0);
	return (1);
}
