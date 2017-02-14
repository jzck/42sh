#include "lexer.h"

void	lexer_init(t_lexer *lexer)
{
	lexer->str = NULL;
	lexer->pos = 0;
	lexer->state = DEFAULT;
	lexer->stack = NULL;
	lexer->heredoc_stack = NULL;
}
