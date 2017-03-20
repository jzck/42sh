/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:39:37 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/20 14:37:26 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cliopts	g_export_opts[] =
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
	if (cliopts_get((char**)av, g_export_opts, &data))
		ft_perror();
	if (data.flag & BT_EXPORT_LP)
		return (bt_export_print());
	av = data.av_data;
	while (*av)
	{
		equal = ft_strchr(*av, '=');
		if (equal)
			*equal = 0;
		else
			equal = ft_getenv(data_singleton()->local_var, *av);
		equal ? equal++ : equal;
		builtin_setenv("internal", (char*[]){"global", *av, equal}, NULL);
		builtin_unsetenv("internal", (char*[]){"local", *av, NULL}, NULL);
		av++;
	}
	return (0);
}
