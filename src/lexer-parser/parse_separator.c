#include "lexer_parser.h"

int		parse_separator(t_btree **ast, t_list *start, t_list *lst)
{
	ft_parse(&(*ast)->right, lst->next);
	ft_lstdelone(&lst, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}
