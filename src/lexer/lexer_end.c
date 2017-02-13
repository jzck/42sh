#include "lexer.h"

int		lexer_end(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	DG("check");
	if (*alst && (lexer->state == QUOTE
			|| lexer->state == DQUOTE
			|| lexer->state == BQUOTE))
	{
		token = (*alst)->content;
		ft_strappend(&lexer->str, (char[]){'\n', 0});
		token_append(token, lexer, 1, 0);
		lexer->pos++;
		return (0);
	}
	return (0);
}
