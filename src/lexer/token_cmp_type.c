#include "lexer.h"

int		token_cmp_type(t_token *token, t_type *ref)
{
	return (token->type - *ref);
}
