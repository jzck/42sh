/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/22 16:21:49 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define SETERR_0 "%s: %s: invalid variable name"

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
	char	*esc;
	int		ret;

	(void)path;
	(void)envp;
	if (!av || !av[0])
		return (1);
	env = (ft_strcmp(av[0], "local") == 0) ? &data_singleton()->local_var :
		&data_singleton()->env;
	if (!av[1])
	{
		ft_sstrprint(*env, '\n');
		ft_putchar('\n');
	}
	else
	{
		esc = ft_strnew((ft_strlen(av[1]) >> 3) + 1);
		ret = word_is_assignment((char *[]){av[1], (esc + 1)});
		ft_strdel(&esc);
		if (!ret && ft_strcmp(av[1], "?"))
			return (SH_ERR(SETERR_0, av[0], av[1]));
		assign_var(av, env);
	}
	return (0);
}
