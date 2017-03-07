/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:08:12 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 15:50:56 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof		g_setprocessmap[] =
{
	{TK_NEWLINE, NULL},
	{TK_SEMI, NULL},
	{TK_AMP, NULL},
	{TK_AND_IF, NULL},
	{TK_OR_IF,NULL},
	{TK_PIPE, NULL},
	{TK_WHILE, NULL},
	{TK_IF, NULL},
	{TK_ELIF, NULL},
	{TK_ELSE, NULL},
	{TK_UNTIL, NULL},
	{TK_FOR, NULL},
	{TK_CASE, NULL},
	{TK_PAREN_OPEN, NULL},
	{TK_ASSIGNEMENT_WORD, NULL},
	{MATH, NULL},
	/* {TK_SUBSHELL, &exec_}, */
	{CMD, &set_process_cmd},
	{0, NULL}
};

int		set_process_map(t_process *p, t_btree *ast, t_cmd *cmd)
{
	int			i;

	i = 0;
	if (!ast)
		return (0);
	while (g_setprocessmap[i].id)
	{
		if (p->type == g_setprocessmap[i].id)
			return ((*g_setprocessmap[i].f)(p, ast, cmd));
		i++;
	}
	return (0);
}
