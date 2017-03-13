/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:39:37 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/13 19:00:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_export(const char *path, char *const av[], char *const envp[])
{
	char	*equal;

	if ((equal = ft_strchr(av[1], '=')))
	{
		*equal = 0;
		builtin_setenv(path, (char*[]){"setenv", av[1], equal + 1}, envp);
	}
	return (0);
}
