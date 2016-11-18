#include "lexer.h"

int		lexer_quote(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	if (*str == '\'')
		return (ft_tokenize(&(*alst)->next, str + 1, WORD));
	token_append(token, *str);
	return (lexer_quote(alst, str + 1));
}
