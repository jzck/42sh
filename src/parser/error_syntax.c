/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:15:35 by ariard            #+#    #+#             */
/*   Updated: 2017/03/17 18:08:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define SYNTERR_0 "{red}syntax error near unexpected token `%s'{eoc}\n"
#define SYNTERR_1 "{red}syntax error near unexpected EOF{eoc}"

static t_errormatch	g_errormatch[] =
{
	{TK_NEWLINE, "newline"},
	{TK_SEMI, ";"},
	{TK_DSEMI, ";;"},
	{TK_PIPE, "|"},
	{TK_AMP, "&"},
	{TK_LESS, "<"},
	{TK_GREAT, ">"},
	{TK_DGREAT, ">>"},
	{TK_LESSAND, "<&"},
	{TK_GREATAND, ">&"},
	{TK_LESSGREAT, "<>"},
	{TK_CLOBBER, ">|"},
	{TK_DLESS, "<<"},
	{TK_DLESSDASH, "<<-"},
	{TK_AND_IF, "&&"},
	{TK_OR_IF, "||"},
	{TK_IF, "if"},
	{TK_THEN, "then"},
	{TK_ELSE, "else"},
	{TK_ELIF, "elif"},
	{TK_FI, "fi"},
	{TK_DO, "do"},
	{TK_DONE, "done"},
	{TK_CASE, "case"},
	{TK_ESAC, "esac"},
	{TK_WHILE, "while"},
	{TK_UNTIL, "until"},
	{TK_FOR, "for"},
	{TK_LBRACE, "{"},
	{TK_RBRACE, "}"},
	{TK_PAREN_OPEN, "("},
	{TK_PAREN_CLOSE, ")"},
	{TK_BANG, "!"},
	{TK_IN, "in"},
	{0, NULL},
};

int				error_syntax(t_list **lst)
{
	t_token		*token;
	int			i;

	if (!*lst)
		return (0);
	token = (*lst)->content;
	i = 0;
	while (g_errormatch[i].token)
	{
		if (g_errormatch[i].token == token->type)
		{
			ft_dprintf(2, SYNTERR_0, g_errormatch[i].error);
			return (0);
		}
		i++;
	}
	ft_dprintf(2, SYNTERR_0,
		token->data);
	return (0);
}

int				error_eof(void)
{
	ft_dprintf(2, SYNTERR_1);
	return (1);
}
