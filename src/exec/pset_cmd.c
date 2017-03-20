/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:41:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 16:28:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			pset_cmd(t_process *p, t_btree *ast)
{
	t_btree	*func;

	if (ast && !(p->data.cmd.av =
				token_to_argv(((t_astnode *)ast->item)->data.cmd.token, 1)))
		return ((p->type = PROCESS_EMPTY) ? 0 : 0);
	if ((func = is_function(p)))
	{
		p->data.function.content = func;
		p->type = PROCESS_FUNCTION;
	}
	else if ((p->data.cmd.execf = is_builtin(p)))
		p->type = PROCESS_BUILTIN;
	else if ((p->type = PROCESS_FILE))
	{
		p->data.cmd.stat = ft_memalloc(sizeof(struct stat));
		p->data.cmd.execf = &execve;
		p->data.cmd.path = ft_strchr(p->data.cmd.av[0], '/') ?
			ft_strdup(p->data.cmd.av[0]) : ft_hash(p->data.cmd.av[0]);
		if (p->data.cmd.path && !access(p->data.cmd.path, F_OK)
				&& stat(p->data.cmd.path, p->data.cmd.stat) == -1)
			return (-1);
	}
	return (0);
}
