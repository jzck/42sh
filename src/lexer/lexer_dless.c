#include "minishell.h"

int		lexer_dless(t_list **alst, t_lexer *lexer)
{
	t_list	*heredoc_lst;
	t_token	*eof_tok;
	t_token	*heredoc_tok;

	(void)alst;
	(void)lexer;
	heredoc_lst = *(t_list**)lexer->heredoc_stack->content;
	heredoc_tok = heredoc_lst->content;
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
	if (ft_strcmp(eof_tok->data, lexer->str + lexer->pos) == 0)
	{
		pop(&lexer->stack);
		pop(&lexer->heredoc_stack);
		while (lexer->str[++lexer->pos])
			;
		ft_strappend(&lexer->str, (char[]){'\n', 0});
		lexer->pos++;
		return (0);
	}
	else
		while (lexer->str[lexer->pos])
			token_append_char(heredoc_tok, lexer->str[lexer->pos++], 0, 0);
	return (lexer_end(alst, lexer));
}
