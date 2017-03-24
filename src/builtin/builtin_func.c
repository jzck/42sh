/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:03:02 by wescande          #+#    #+#             */
/*   Updated: 2017/03/24 17:01:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define FUNC_USAGE	"func"

int			builtin_func(const char *path,
							char *const argv[], char *const envp[])
{
	t_list	*list;
	char	**name;
	t_btree	**ast;

	(void)envp;
	(void)path;
	if (!argv || !argv[0] || argv[1])
		return (SH_ERR("usage: %s", FUNC_USAGE) ? 1 : 1);
	list = data_singleton()->lst_func;
	while (list)
	{
		if (!(ast = list->content))
			return (SH_ERR("unexpected error"));
		name = token_to_argv(((t_astnode *)(*ast)->item)->data.cmd.token, 1);
		if (name && name[0])
		{
			DG();
			ft_putendl(name[0]);
		}
		ft_tabdel(&name);
		list = list->next;
	}
	return (0);
}
