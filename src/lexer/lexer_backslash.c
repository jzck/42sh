#include "lexer.h"

int		lexer_backslash(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	token_append(token, str[1]);
	return (ft_tokenize(alst, str + 2, WORD));
}
