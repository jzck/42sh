/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:03:32 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 16:20:19 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_printmap[] =
{
	{PROCESS_FUNCTION, process_print_function},
	{PROCESS_BUILTIN, NULL},
	{PROCESS_FILE, NULL},
	{PROCESS_SUBSHELL, process_print_subshell},
	{PROCESS_WHILE, process_print_while},
	{PROCESS_UNTIL, process_print_until},
	{PROCESS_IF, process_print_if},
	{PROCESS_FOR, process_print_for},
	{PROCESS_CASE, process_print_case},
	{0, NULL}
};

void	process_print(t_process *p)
{
	if (p->type == PROCESS_BUILTIN || p->type == PROCESS_FUNCTION)
	{
		process_print_cmd(p);
		return ;
	}
	if (p->type >= PROCESS_MAX)
		return ;
	if (g_printmap[p->type].f)
		(g_printmap[p->type].f)();
}
