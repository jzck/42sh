/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:39:37 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/18 11:46:32 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cliopts	export_opts[] =
{
	{'p', NULL, BT_EXPORT_LP, 0, NULL},
	{0, NULL, 0, 0, NULL},
};

int					bt_export_print(void)
{
	char	**env;
	char	*equal;

	env = data_singleton()->env;
	while (*env)
	{
		if ((equal = ft_strchr(*env, '=')))
			ft_printf("export %s\n", *env);
		else
			ft_printf("export %s\n", *env);
		env++;
	}
	return (0);
}

int					builtin_export(
		const char *path, char *const av[], char *const envp[])
{
	char		*equal;
	t_btexport	data;

	(void)envp;
	(void)path;
	data.flag = 0;
	if (cliopts_get((char**)av, export_opts, &data))
		ft_perror();
	if (data.flag & BT_EXPORT_LP)
		return (bt_export_print());
	av = cliopts_getdata((char**)av);
	while (*av)
	{
		if ((equal = ft_strchr(*av, '=')))
		{
			*equal = 0;
			builtin_setenv("internal", (char*[]){"global", *av, equal + 1}, NULL);
		}
		else
		{
			equal = ft_getenv(data_singleton()->local_var, *av);
			builtin_setenv("internal", (char*[]){"global", *av, equal}, NULL);
		}
		builtin_unsetenv("internal", (char*[]){"local", *av, NULL}, NULL);
		av++;
	}
	return (0);
}
