/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:32:59 by ariard            #+#    #+#             */
/*   Updated: 2017/02/19 17:34:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_treematch			g_treematch[] =
{
	{TK_N_WORD, &add_cmd},
	{TK_PIPE, &add_sep},
	{TK_SEMI, &add_sep},
	{TK_GREAT, &add_sep},
	{TK_LESS, &add_sep},
	{TK_OR_IF, &add_sep},
	{TK_AND_IF, &add_sep},
	{TK_WHILE, &add_cmd},
	{TK_DO, &add_cmd},
	{TK_DONE, &add_cmd},
	{TK_NEWLINE, &add_sep},
	{0, NULL},
};

static int	isseparator(int type, int cache)
{
	if (type == TK_NEWLINE && (cache == TK_WHILE || cache == TK_DO 
		|| cache == TK_NEWLINE))
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
