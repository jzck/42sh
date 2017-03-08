/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 02:06:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_freemap[] =
{
	{PROCESS_FUNCTION, NULL},
	{PROCESS_BUILTIN, NULL},
	{PROCESS_FILE, NULL},
	{PROCESS_SUBSHELL, NULL},
	{PROCESS_WHILE, NULL},
	{PROCESS_UNTIL, NULL},
	{PROCESS_IF, NULL},
	{PROCESS_FOR, NULL},
	{PROCESS_CASE, NULL},
	{0, NULL}
};

void	process_free(void *content, size_t content_size)
{
	t_process	*p;

	p = content;
	DG();
	(void)content_size;
	if (p->type >= PROCESS_MAX)
		return ;
	if (!g_freemap[p->type].f)
		return ;
	(g_freemap[p->type].f)(p);
	ft_lstdel(&p->redirs, ft_lst_cfree);
	free(p);
	DG();
}
