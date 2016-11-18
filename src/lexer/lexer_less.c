#include "lexer.h"

int		lexer_less(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	if (*str == '&')
	{
		token_append(token, *str);
		return (lexer_lessand(alst, str + 1));
	}
	else if (*str == '<')
	{
		token->type = TK_DLESS;
		token_append(token, *str);
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
	else
	{
		token->type = TK_LESS;
		token_append(token, *str);
		return (ft_tokenize(alst, str + 1, DEFAULT));
	}
}
