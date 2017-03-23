/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:25:23 by ariard            #+#    #+#             */
/*   Updated: 2017/03/23 16:27:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*is_already_func(t_btree **new)
{
	t_list	*tmp;
	t_btree	**ast;
	char	**new_name;
	char	**old_name;
	int		ret;

	tmp = data_singleton()->lst_func;
	new_name = token_to_argv(((t_astnode *)(*new)->item)->data.cmd.token, 1);
	ret = 1;
	while (tmp && ret)
	{
		if ((ast = tmp->content) && !*ast)
			break ;
		old_name = token_to_argv(((t_astnode *)
					(*ast)->item)->data.cmd.token, 1);
		ret = (new_name && new_name[0] && old_name && old_name[0]
			&& !ft_strcmp(new_name[0], old_name[0])) ? 0 : 1;
		ft_tabdel(&old_name);
		tmp = (ret) ? tmp->next : tmp;
	}
	ft_tabdel(&new_name);
	if (!ret)
		return (tmp);
	return (NULL);
}

int			exec_func(t_btree **ast)
{
	t_btree	*func_ast;
	t_list	*old_func;

	func_ast = btree_map(*ast, &node_copy);
	if ((old_func = is_already_func(&func_ast)))
	{
		ft_lst_delif(&data_singleton()->lst_func,
			old_func->content, &ft_addrcmp, &tree_func_free);
	}
	ft_lsteadd(&data_singleton()->lst_func, ft_lstnew(&func_ast, sizeof(*ast)));
	return (0);
}
