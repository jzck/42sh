#include "lexer.h"

int		lexer_lessand(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_LESSAND;
	if (ft_isdigit(*str))
	{
		token_append(token, *str);
		return (lexer_lessand(alst, str + 1));
	}
	else if (*str == '-')
	{
		token_append(token, *str);
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
	return (ft_tokenize(alst, str, DEFAULT));
}
