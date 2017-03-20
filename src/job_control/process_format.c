/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:05:55 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 10:54:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirection_print(t_redir *redir)
{
	char	symbol[3];

	if (redir->type == TK_LESS)
		ft_strcpy(symbol, "<");
	else if (redir->type == TK_GREAT)
		ft_strcpy(symbol, ">");
	else if (redir->type == TK_DLESS)
		ft_strcpy(symbol, "<<");
	else if (redir->type == TK_DGREAT)
		ft_strcpy(symbol, ">>");
	else if (redir->type == TK_LESSAND)
		ft_strcpy(symbol, "<&");
	else if (redir->type == TK_GREATAND)
		ft_strcpy(symbol, ">&");
	ft_printf(" %i%s%s", redir->n, symbol, redir->word);
	return (0);
}

static void	process_format_state(t_process *p)
{
	char	*statestr;

	statestr = NULL;
	if (p->state == PROCESS_RUNNING)
		ft_asprintf(&statestr, "running");
	else if (p->state == PROCESS_SUSPENDED)
		ft_asprintf(&statestr, "suspended");
	else if (p->state == PROCESS_CONTINUED)
	{
		ft_asprintf(&statestr, "continued");
		p->state = PROCESS_RUNNING;
	}
	else if (p->state == PROCESS_COMPLETED)
	{
		if (WIFSIGNALED(p->status))
			ft_asprintf(&statestr, strsignal(WTERMSIG(p->status)));
		else if (p->status == 0)
			ft_asprintf(&statestr, "done");
		else
			ft_asprintf(&statestr, "%s %i", "exit", WEXITSTATUS(p->status));
	}
	ft_printf("%-*s\t", 12, statestr);
	ft_strdel(&statestr);
}

static void	process_format_com_long(t_list **plist)
{
	t_process	*p;

	p = (*plist)->content;
	if (p->map.print)
		(p->map.print)(p);
	ft_lstiter(p->redirs, redirection_print);
	if ((*plist)->next)
		ft_putstr(" |");
	(*plist) = (*plist)->next;
}

static void	process_format_com_short(t_list **plist, t_flag state)
{
	t_process	*p;

	while (*plist)
	{
		p = (*plist)->content;
		if (p->state != state)
			break ;
		if (p->state == PROCESS_CONTINUED)
			p->state = PROCESS_RUNNING;
		if (p->map.print)
			(p->map.print)(p);
		ft_lstiter(p->redirs, redirection_print);
		if ((*plist)->next)
			ft_putstr(" | ");
		(*plist) = (*plist)->next;
	}
}

void		process_format(t_list **plist, int firstp, int opts)
{
	t_process	*p;

	p = (*plist)->content;
	if (!firstp)
		ft_printf("       ");
	if (opts & JOBS_OPTS_L)
		ft_printf("%i ", p->pid);
	process_format_state(p);
	if (opts & JOBS_OPTS_L)
		process_format_com_long(plist);
	else
		process_format_com_short(plist, p->state);
	ft_putchar('\n');
}
