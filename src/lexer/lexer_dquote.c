#include "lexer.h"

int		lexer_dquote(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = WORD;
	if (*str == '\"')
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	if (*str == '\\')
	{
		token_append(token, *str);
		token_append(token, *(str + 1));
		return (lexer_dquote(alst, str + 2));
	}
	token_append(token, *str);
	return (lexer_dquote(alst, str + 1));
}
