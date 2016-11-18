#include "lexer.h"

int		lexer_default(t_list **alst, char *str)
{
	t_lexstate	state;

	state = DEFAULT;
	if (*str == '>')
		state = GREAT;
	else if (*str == '<')
		state = LESS;
	else if (ft_isdigit(*str))
		state = NUMBER;
	else
		state = WORD;
	token_append((*alst)->content ,*str);
	return (ft_tokenize(alst, str + 1, state));
}
