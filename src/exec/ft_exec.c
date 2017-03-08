/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:30:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 11:57:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_execmap[] =
{
	{TK_NEWLINE, &exec_semi},
	{TK_SEMI, &exec_semi},
	{TK_AMP, &exec_ampersand},
	{TK_AND_IF, &exec_and_if},
	{TK_OR_IF, &exec_or_if},
	{TK_PIPE, &exec_pipe},
	{TK_WHILE, &exec_leaf},
	{TK_IF, &exec_leaf},
	{TK_ELIF, &exec_elif},
	{TK_ELSE, &exec_else},
	{TK_UNTIL, &exec_leaf},
	{TK_FOR, &exec_leaf},
	{TK_CASE, &exec_leaf},
	{TK_PAREN_OPEN, &exec_case_branch},
	{TK_ASSIGNEMENT_WORD, &exec_var},
	{MATH, &exec_math},
	{SUBSHELL, &exec_leaf},
	{CMD, &exec_leaf},
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
	while (g_execmap[i].id)
	{
		if (item->type == g_execmap[i].id)
			return ((*g_execmap[i].f)(ast));
		i++;
	}
	return (0);
}
