/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 20:19:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* t_itof	g_freemap[] = */
/* { */
/* 	{PROCESS_FUNCTION, process_free_subshell}, */
/* 	{PROCESS_BUILTIN, process_free_cmd}, */
/* 	{PROCESS_FILE, process_free_cmd}, */
/* 	{PROCESS_SUBSHELL, process_free_subshell}, */
/* 	{PROCESS_WHILE, process_free_cond}, */
/* 	{PROCESS_UNTIL, process_free_cond}, */
/* 	{PROCESS_IF, process_free_cond}, */
/* 	{PROCESS_FOR, process_free_list}, */
/* 	{PROCESS_CASE, process_free_list}, */
/* 	{PROCESS_EMPTY, NULL}, */
/* }; */

void	process_free(void *content, size_t content_size)
{
	t_process	*p;

	p = content;
	(void)content_size;
	/* if (p->type >= PROCESS_MAX) */
	/* 	return ; */
	/* if (g_freemap[p->type].f) */
	/* 	(g_freemap[p->type].f)(p); */
	if (p->map.free)
		(p->map.free)(p);
	ft_lstdel(&p->redirs, redir_free);
	free(p);
}
