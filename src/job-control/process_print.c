/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:03:32 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 20:44:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_printmap[] =
{
	{PROCESS_FUNCTION, process_print_function},
	{PROCESS_BUILTIN, process_print_cmd},
	{PROCESS_FILE, process_print_cmd},
	{PROCESS_SUBSHELL, process_print_subshell},
	{PROCESS_WHILE, process_print_while},
	{PROCESS_UNTIL, process_print_until},
	{PROCESS_IF, process_print_if},
	{PROCESS_FOR, process_print_for},
	{PROCESS_CASE, process_print_case},
};

void	process_print(t_process *p)
{
	if (p->type >= PROCESS_MAX)
		return ;
	if (g_printmap[p->type].f)
		(*g_printmap[p->type].f)(p);
}
