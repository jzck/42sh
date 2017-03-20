/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 14:38:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	assign_var(char *const av[], char ***env)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_str3join(av[1], "=", av[2]);
	while ((*env) && (*env)[++i])
	{
		if (ft_strcmp((*env)[i], av[1]) == '='
				&& ft_strlen(av[1]) == ft_strlenchr((*env)[i], '='))
		{
			ft_strdel(&(*env)[i]);
			(*env)[i] = str;
			return (0);
		}
	}
	*env = ft_sstradd(*env, str);
	ft_strdel(&str);
	return (0);
}

int			builtin_setenv(const char *path,
		char *const av[], char *const envp[])
{
	char	***env;

	(void)path;
	if (!av || !av[0])
		return (builtin_return_status(0, 1));
	if (ft_strcmp(av[0], "local") == 0)
		env = &data_singleton()->local_var;
	else
		env = &data_singleton()->env;
	if (!av[1])
	{
		ft_sstrprint(*env, '\n');
		ft_putchar('\n');
	}
	else
		assign_var(av, env);
	return (envp ? builtin_return_status(0, 0) : 0);
}
