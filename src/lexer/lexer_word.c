#include "lexer.h"

int		lexer_word(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	if (*str == '>')
		return (ft_tokenize(&(*alst)->next, str, GREAT));
	else if (*str == '<')
		return (ft_tokenize(&(*alst)->next, str, LESS));
	token_append(token, *str);
	return (ft_tokenize(alst, str + 1, WORD));
}
