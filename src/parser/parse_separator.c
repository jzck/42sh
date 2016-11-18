#include "parser.h"

int		parse_separator(t_btree **ast, t_list *start, t_list *lst)
{
	ft_parse(&(*ast)->right, lst->next);
	ft_lst_delif(&start, lst->content, &ft_addrcmp, &token_free);
	ft_parse(&(*ast)->left, start);
	return (0);
}
