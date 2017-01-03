/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:30:32 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 15:18:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_execmap	g_execmap[] =
{
	{TK_AND_IF, &exec_and_if},
	{TK_OR_IF, &exec_or_if},
	{TK_SEMI, &exec_semi},
	{TK_AMP, &exec_ampersand},
	{TK_PIPE, &exec_pipe},
	{TK_LESS, &exec_less},
	{TK_GREAT, &exec_great},
	{TK_DGREAT, &exec_dgreat},
	{TK_COMMAND, &exec_command},
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
			/* return ((*g_execmap[i].f)(ast)); */
			(*g_execmap[i].f)(ast);
		i++;
	}
	return (0);
}
