/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:08:12 by wescande          #+#    #+#             */
/*   Updated: 2017/03/13 17:39:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof		g_setprocessmap[] =
{
	{TK_WHILE, &set_process_while},
	{TK_IF, &set_process_if},
	{TK_ELIF, NULL},
	{TK_ELSE, NULL},
	{TK_UNTIL, &set_process_until},
	{TK_FOR, &set_process_for},
	{TK_CASE, &set_process_case},
	{TK_PAREN_OPEN, NULL},
	{TK_ASSIGNEMENT_WORD, NULL},
	{MATH, NULL},
	{SUBSHELL, &set_process_subshell},
	{CMD, &set_process_cmd},
	{0, NULL}
};

int		set_process_map(t_process *p, t_btree *ast)
{
	int			i;
	t_astnode	*item;

	i = -1;
	if (!ast)
		return (0);
	item = ast->item;
	while (g_setprocessmap[++i].id)
		if (item->type == g_setprocessmap[i].id)
		{
			if (!g_setprocessmap[i].f)
				return (1);
			return ((*g_setprocessmap[i].f)(p, ast));
		}
	return (1);
}
