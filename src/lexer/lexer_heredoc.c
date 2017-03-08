/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:51:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 17:46:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_heredoc(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	token = (*alst)->content;
	token->type = HEREDOCDATA;
	while (lexer->str[lexer->pos])
		if (token_append_char(token, lexer->str[lexer->pos++], esc, esc2))
			return (1);
	return (0);
	/* heredoc_lst = *(t_list**)lexer->heredoc_stack->content; */
	/* heredoc_tok = heredoc_lst->content; */
	/* if (!(heredoc_lst->next)) */
	/* { */
	/* 	ft_dprintf(2, "{red}%s: parse error near `\\n'{eoc}\n", SHELL_NAME); */
	/* 	return (1); */
	/* } */
	/* eof_tok = heredoc_lst->next->content; */
	/* if (!(eof_tok->type == TK_WORD)) */
	/* { */
	/* 	ft_dprintf(2, "{red}%s: expected word token after <<{eoc}\n", SHELL_NAME); */
	/* 	return (1); */
	/* } */
	/* DG("heredoc contains [%s]", heredoc_tok->data); */
	/* DG("heredoc ends at [%s]", eof_tok->data); */
	/* DG("input is [%s]", lexer->str + lexer->pos); */
	/* if (ft_strcmp(eof_tok->data, lexer->str + lexer->pos) == 0) */
	/* { */
	/* 	/1* pop(&lexer->stack); *1/ */
	/* 	pop(&lexer->heredoc_stack); */
	/* 	while (lexer->str[++lexer->pos]) */
	/* 		; */
	/* 	ft_strappend(&lexer->str, (char[]){'\n', 0}); */
	/* 	lexer->pos++; */
	/* 	return (0); */
	/* } */
	/* else */
	/* 	while (lexer->str[lexer->pos]) */
	/* 		token_append_char(heredoc_tok, lexer->str[lexer->pos++], 0, 0); */
	/* return (lexer_end(alst, lexer)); */
}
