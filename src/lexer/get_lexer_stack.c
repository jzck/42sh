#include "lexer.h"

int		get_lexer_stack(t_lexer lexer)
{
	return (lexer.stack ? *(int*)lexer.stack->content : 0);
}
