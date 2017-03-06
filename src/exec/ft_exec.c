/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:30:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/04 17:16:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_execmap	g_execmap[] =
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
	/* {TK_SUBSHELL, &exec_}, */
	{CMD, &exec_cmd},
	{0, 0},
};

int		ft_exec(t_btree **ast)
{
	t_astnode	*item;
	int			i;

	i = 0;
	if (!*ast)
		return (0);
	item = (*ast)->item;
	while (g_execmap[i].type)
	{
		if (item->type == g_execmap[i].type)
			return ((*g_execmap[i].f)(ast));
		i++;
	}
	return (0);
}
