/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:30:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 18:15:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_execmap	g_execmap[] =
{
	{TK_NEWLINE, &exec_semi},
	{TK_AND_IF, &exec_and_if},
	{TK_OR_IF, &exec_or_if},
	{TK_SEMI, &exec_semi},
	{TK_AMP, &exec_ampersand},
	{TK_PIPE, &exec_pipe},
	{TK_LESS, &exec_redir},
	{TK_GREAT, &exec_redir},
	{TK_DLESS, &exec_redir},
	{TK_DGREAT, &exec_redir},
	{TK_LESSAND, &exec_redir},
	{TK_GREATAND, &exec_redir},
	{TK_WHILE, &exec_while},
	{TK_IF, &exec_if},
	{TK_ELIF, &exec_elif},
	{TK_ELSE, &exec_else},
	{TK_UNTIL, &exec_until},
	{TK_SUBSHELL, &exec_command},
	{TK_WORD, &exec_command},
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
		{
			DG("match : %s and %s",
			read_state(item->type), read_state(g_execmap[i].type));
			/* return ((*g_execmap[i].f)(ast)); */
			(*g_execmap[i].f)(ast);
		}
		i++;
	}
	return (0);
}
