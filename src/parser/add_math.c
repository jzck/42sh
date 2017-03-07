#include "parser.h"

int	ismath(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == SUBSHELL && token->type == SUBSHELL)
		{
			node->type = MATH;
			return (1);
		}
		if (node->type == MATH && token->type == TK_PAREN_CLOSE)
			return (1);
	}
	return (0);
}


int	ismath_expr(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == MATH && token->type == TK_WORD)
			return (1);
	}
	return (0);
}
