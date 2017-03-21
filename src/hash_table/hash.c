/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:06:19 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/21 17:40:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*g_hash[MAX_HASH] = {NULL};

char	*ft_hash(char *cmd)
{
	char *path;

	if (!(path = ft_is_hash(cmd)))
		path = ft_add_hash(cmd);
	return (path);
}
