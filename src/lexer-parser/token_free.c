#include "lexer_parser.h"

void	token_free(void *data, size_t size)
{
	t_token		*token;

	(void)size;
	token = data;
	ft_strdel(&token->data);
	free(token);
}
