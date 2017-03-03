/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:32:59 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 15:08:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_treematch			g_treematch[] =
{
	{TK_WORD, &add_cmd},
	{TK_PIPE, &add_sep},
	{TK_SEMI, &add_sep},
	{TK_GREAT, &add_cmd},
	{TK_LESS, &add_cmd},
	{TK_DGREAT, &add_cmd},
	{TK_DLESS, &add_cmd},
	{TK_OR_IF, &add_sep},
	{TK_AND_IF, &add_sep},
	{TK_AMP, &add_sep},
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
	{TK_IN, &add_cmd},
	{TK_DSEMI, &add_cmd},
	{TK_PAREN_OPEN, &add_cmd},
	{TK_PAREN_CLOSE, &add_cmd},
	{TK_FOR, &add_cmd},
	{TK_ASSIGNEMENT_WORD, &add_cmd},
	{SUBSHELL, &add_cmd},
	{TK_LBRACE, &add_cmd},
	{TK_RBRACE, &add_cmd},
	{CLOSE_LIST, &add_cmd},
	{0, NULL},
};

static int	isseparator(t_token *token, int cache)
{
	if (token->type == TK_NEWLINE && (cache == TK_WHILE || cache == TK_DO
		|| cache == TK_NEWLINE || cache == TK_THEN || cache == TK_IN
		|| cache == TK_DSEMI))
		return (0);
//check cache == WORD
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
	if (token->type == TK_PAREN_OPEN && cache != TK_IN && cache != TK_DSEMI
		&& cache != TK_WORD)
		token->type = SUBSHELL;
	if (token->type == TK_PAREN_CLOSE && cache == TK_PAREN_OPEN)
		token->type = CLOSE_LIST;	
	while (g_treematch[i].type)
	{
		if ((isseparator(token, cache) && g_treematch[i].type == token->type))
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
