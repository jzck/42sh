#include "parser.h"

int		iscase(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == TK_PAREN_OPEN && node->full == 0)
		{
	//		DG("go right");
			return (1);
		}
		if ((node->type == TK_CASE || node->type == TK_PAREN_OPEN 
			|| iscase(&(*ast)->right, lst) == 1) && token->type == TK_WORD
			&& node->pattern == 0)
		{
	//		DG("add pattern");
			return (2);
		}
		if ((node->type == TK_CASE || iscase(&(*ast)->right, lst) == 4) 
			&& token->type == TK_PAREN_OPEN)
		{
	//		DG("new branch");
			return (3);
		}
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP) && iscase(&(*ast)->right, lst) == 1)
		{
//			DG(" go right");
			return (1);
		}
		if (node->type == TK_PAREN_OPEN && node->nest == 0)
			return (4);
	}
	return (0);
}

int		add_case_cmd(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	DG("add case cmd");
	if (token->type == TK_CASE && node->type == TK_PAREN_OPEN)
	{
		DG("nesting");
		node->nest++;
	}
	if (token->type == TK_ESAC && node->type == TK_PAREN_OPEN && node->nest > 0)
	{
		DG("nesting less");
		node->nest--;
	}
	else if (token->type == TK_DSEMI && node->type == TK_PAREN_OPEN)
		return ((node->full = 1));
	return (add_cmd(&(*ast)->right, lst));
}	

int		add_case_sep(t_btree **ast, t_list **lst)
{
	return (add_sep(&(*ast)->right, lst));
}

int		add_pattern(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;
	
	token = (*lst)->content;
	node = (*ast)->item;
	node->data.redir.word.word = ft_strdup(token->data);
	node->pattern = 1;
	return (0);
}
