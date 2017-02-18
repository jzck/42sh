/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:37:43 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/18 16:51:43 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_hash_lst_print(t_list *list)
{
	while (list)
	{
		ft_putstr(((t_hash *)list->content)->key);
		ft_putchar('=');
		ft_putstr(((t_hash *)list->content)->path);
		ft_putchar('\n');
		list = list->next;
	}
}

static int	ft_hash_opt(char *const av[])
{
	if (av[1] && !ft_strcmp(av[1], "-r"))
		ft_free_hash_table();
	else if (av[1])
	{
		ft_dprintf(2, "42sh: hash: invalid option\n");
		ft_dprintf(2, "hash: usage: hash [-r]\n");
		return (1);
	}
	return (0);
}

int			builtin_hash(const char *path, char *const av[], char *const envp[])
{
	int i;

	(void)path;
	(void)envp;
	if (ft_hash_opt(av))
		return (0);
	i = 0;
	while (i < MAX_HASH)
	{
		if (g_hash[i])
			ft_hash_lst_print(g_hash[i]);
		++i;
	}
	return (0);
}
