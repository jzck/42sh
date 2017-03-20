/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:43:34 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/20 14:27:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_unset(const char *path, char *const av[], char *const envp[])
{
	char	*tmp;
	char	**av_tmp;

	tmp = av[0];
	av_tmp = (char **)av;
	av_tmp[0] = "local";
	builtin_unsetenv(path, av, envp);
	av_tmp[0] = tmp;
	return (builtin_unsetenv(path, av, envp));
}
