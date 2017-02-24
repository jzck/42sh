/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:32:59 by ariard            #+#    #+#             */
/*   Updated: 2017/02/24 16:24:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_treematch			g_treematch[] =
{
	{TK_WORD, &add_cmd},
	{TK_PIPE, &add_sep},
	{TK_SEMI, &add_sep},
	{TK_GREAT, &add_sep},
	{TK_LESS, &add_sep},
	{TK_OR_IF, &add_sep},
	{TK_AND_IF, &add_sep},
	{TK_WHILE, &add_cmd},
	{TK_UNTIL, &add_cmd},
	{TK_DO, &add_cmd},
	{TK_DONE, &add_cmd},
	{TK_IF, &add_cmd},
	{TK_ELIF, &add_cmd},
	{TK_ELSE, &add_cmd},
	{TK_THEN, &add_cmd},
	{TK_FI, &add_cmd},
	{TK_NEWLINE, &add_sep},
	{TK_CASE, &add_cmd},
	{TK_ESAC, &add_cmd},
	{TK_PAREN_OPEN, &add_cmd},
	{TK_PAREN_CLOSE, &add_cmd},
	{TK_FOR, &add_cmd},
	{0, NULL},
};

static int	isseparator(int type, int cache)
{
	if (type == TK_NEWLINE && (cache == TK_WHILE || cache == TK_DO
		|| cache == TK_NEWLINE || cache == TK_THEN || cache == TK_IN
		|| cache == TK_WORD))
		return (0);
	return (1);
}

int			build_tree(t_btree **ast, t_list **lst)
{
	int			i;
	static int	cache;
	t_token	*token;

	i = 0;
	token = (*lst)->content;
//check bug de cache case ?
//	cache = token->type;
	while (g_treematch[i].type)
	{
		if (g_treematch[i].type == token->type
				&& isseparator(token->type, cache))
		{

			DG("func TK : '%s' TK : '%s'",
			read_state(g_treematch[i].type) ,read_state(token->type));
			cache = token->type;
			return (g_treematch[i].add(ast, lst));
		}
		i++;
	}
	return (0);
}
