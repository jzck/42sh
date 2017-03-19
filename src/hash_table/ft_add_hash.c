/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:20:11 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/19 16:40:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_add_hash(char *cmd)
{
	int		id;
	t_hash	hash;

	if (!(hash.path = ft_findexec(ft_getenv(
							data_singleton()->env, "PATH"), cmd)))
		return (NULL);
	hash.key = ft_strdup(cmd);
	id = ft_hash_str(cmd);
	ft_lsteadd(&(g_hash[id]), ft_lstnew(&hash, sizeof(t_hash)));
	return (ft_strdup(hash.path));
}
