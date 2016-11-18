#include "lexer.h"

int		lexer_number(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	if (*str == '>')
	{
		token_append(token, *str);
		return (lexer_great(alst, str + 1));
	}
	else if (*str == '<')
	{
		token_append(token, *str);
		return (lexer_less(alst, str + 1));
	}
	else if (ft_isdigit(*str))
	{
		token_append(token, *str);
		return (lexer_number(alst, str + 1));
	}
	return (ft_tokenize(alst, str, DEFAULT));
}
