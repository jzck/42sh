#include "lexer.h"

int		lexer_great(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	if (*str == '&')
	{
		token_append(token, *str);
		return (lexer_greatand(alst, str + 1));
	}
	else if (*str == '>')
	{
		token->type = TK_DGREAT;
		token_append(token, *str);
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
	else
	{
		token->type = TK_GREAT;
		return (ft_tokenize(&(*alst)->next, str, DEFAULT));
	}
}
