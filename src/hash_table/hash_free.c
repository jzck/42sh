/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:12:22 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/18 14:20:20 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hash_free(void *ptr, size_t size)
{
	(void)size;
	free(((t_hash *)ptr)->key);
	free(((t_hash *)ptr)->path);
	free(ptr);
}

void	ft_free_hash_table(void)
{
	int		i;

	i = 0;
	while (i < MAX_HASH)
	{
		if (g_hash[i])
			ft_lstdel(&g_hash[i], &ft_hash_free);
		++i;
	}
}
