#include "lexer.h"

int		lexer_delim(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	while (ft_is_delim(*str))
		str++;
	if (*token->data)
		return (ft_tokenize(&(*alst)->next, str, DEFAULT));
	else
		return (ft_tokenize(alst, str, DEFAULT));
}
