/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:28:41 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 18:00:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_exit(const char *path, char *const av[], char *const envp[])
{
	int		status;

	(void)path;
	if (av[1])
		status = ft_atoi(av[1]);
	else
		status = ft_atoi(ft_getenv((char**)envp, "?"));
	exit(status);
	return (0);
}
