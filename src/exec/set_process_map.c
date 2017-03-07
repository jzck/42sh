/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:08:12 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 15:11:17 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_setprocessmap		g_setprocessmap[] =
{
	{TK_NEWLINE, &exec_semi},
	{TK_SEMI, &exec_semi},
	{TK_AMP, &exec_ampersand},
	{TK_AND_IF, &exec_and_if},
	{TK_OR_IF, &exec_or_if},
	{TK_PIPE, &exec_pipe},
	{TK_WHILE, &exec_while},
	{TK_IF, &exec_if},
	{TK_ELIF, &exec_elif},
	{TK_ELSE, &exec_else},
	{TK_UNTIL, &exec_until},
	{TK_FOR, &exec_for},
	{TK_CASE, &exec_case},
	{TK_PAREN_OPEN, &exec_case_branch},
	{TK_ASSIGNEMENT_WORD, &exec_var},
	/* {TK_SUBSHELL, &exec_}, */
	{CMD, &exec_cmd},
	{0, 0},
};

int		set_process_map(t_process *p, t_btree *ast, t_cmd *cmd)
{
	int			i;

	i = 0;
	if (!ast)
		return (0);
	while (g_execmap[i].type)
	{
		if (p->type == g_setprocessmap[i].type)
			return ((*g_setprocessmap[i].f)(p, ast, cmd));
		i++;
	}
	return (0);
}
