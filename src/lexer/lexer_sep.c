#include "lexer.h"

int		lexer_sep(t_list **alst, char *str)
{
	t_token		*token;

	if (*alst)
	{
		token = (*alst)->content;
		if (*token->data)
			return (lexer_sep(&(*alst)->next, str));
	}
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	token->type = (*str == ';') ? TK_SEMI : TK_PIPE;
	return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
}
