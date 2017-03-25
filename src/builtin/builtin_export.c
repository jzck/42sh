/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 11:39:37 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/25 01:39:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BT_EXPORT_LP	(1 << 0)
#define EXPORT_USAGE		"usage: export [name[=value] ...] or export -p"

static t_cliopts	g_export_opts[] =
{
	{'p', NULL, BT_EXPORT_LP, 0, NULL, 0},
	{0, NULL, 0, 0, NULL, 0},
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

	(void)path;
	data.flag = 0;
	if (cliopts_get((char**)av, g_export_opts, &data))
		return (ft_perror("export") && SH_ERR(EXPORT_USAGE));
	if (data.flag & BT_EXPORT_LP)
		return (bt_export_print());
	av = data.av_data;
	if (!(data.flag = 0) && !*av)
		bt_export_print();
	while (*av)
	{
		equal = ft_strchr(*av, '=');
		if (equal)
			*(equal++) = 0;
		else
			equal = ft_getenv(data_singleton()->local_var, *av);
		data.flag += builtin_setenv("internal", (char*[]){"export", *av,
			equal}, envp);
		builtin_unsetenv("internal", (char*[]){"local", *av, NULL}, NULL);
		av++;
	}
	return (data.flag ? 1 : 0);
}
