#include "lexer_parser.h"

t_parser	g_parser[] =
{
	{TK_SEMI, &parse_separator},
	{TK_PIPE, &parse_separator},
	{0, 0},
};

int		ft_parse(t_btree **ast, t_list *token)
{
	t_list		*lst;
	t_astnode	item;
	int			i;

	i = 0;
	if(!token)
		return (0);
	while (g_parser[i].type)
	{
		if ((lst = ft_lst_find(token,
						(int [1]){g_parser[i].type}, &token_cmp_type)))
		{
			item.type = g_parser[i].type;
			*ast = btree_create_node(&item, sizeof(item));
			if (g_parser[i].f)
				(*g_parser[i].f)(ast, token, lst);
			return (0);
		}
		else
			i++;
	}
	return (0);
}
