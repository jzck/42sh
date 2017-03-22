/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:29:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 17:51:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_unsetenv(const char *path, char *const av[], char *const envp[])
{
	int		i;
	int		j;
	char	***env;

	(void)envp;
	(void)path;
	env = ft_strcmp(av[0], "local") == 0 ?
		&data_singleton()->local_var : &data_singleton()->env;
	i = 1;
	while (av[i])
	{
		j = 0;
		while (*env && (*env)[j])
		{
			if (ft_strcmp((*env)[j], av[i]) == '=')
				ft_sstrdel(*env, j);
			else
				j++;
		}
		i++;
	}
	return (0);
}
