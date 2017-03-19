/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:06:05 by wescande          #+#    #+#             */
/*   Updated: 2017/03/19 16:42:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_cmd(t_process *p, t_btree *ast)
{
	t_btree		*func;

	if (ast && !(p->data.cmd.av = token_to_argv(((t_astnode *)ast->item)->data.cmd.token, 1)))
	{
		p->type = PROCESS_EMPTY;
		return (0);
	}
	p->data.cmd.path = NULL;
	p->data.cmd.execf = NULL;
	p->data.cmd.stat = ft_memalloc(sizeof(struct stat));
	p->type = PROCESS_FILE;
	if ((func = is_function(p)))
	{
		btree_print(STDBUG, func, &ft_putast);
		p->data.function.content = func;
		p->type = PROCESS_FUNCTION;
	}
	else if ((p->data.cmd.execf = is_builtin(p)))
		p->type = PROCESS_BUILTIN;
	else if (ft_strchr(p->data.cmd.av[0], '/'))
	{
		p->data.cmd.execf = &execve;
		p->data.cmd.path = ft_strdup(p->data.cmd.av[0]);
		if (stat(p->data.cmd.path, p->data.cmd.stat) == -1)
			ft_memdel((void**)&p->data.cmd.stat);
	}
	else if ((p->data.cmd.path = ft_hash(p->data.cmd.av[0])))
	{
		p->data.cmd.execf = &execve;
		if (stat(p->data.cmd.path, p->data.cmd.stat) == -1)
		{
			ft_memdel((void**)&p->data.cmd.stat);
			ft_dprintf(2, "{red}%s: %s: unexpected stat (2) failure\n", SHELL_NAME, p->data.cmd.path);
		}
	}
	return (0);
}
