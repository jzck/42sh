/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:32:59 by ariard            #+#    #+#             */
/*   Updated: 2017/03/13 17:45:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_treematch			g_treematch[] =
{
	{TK_WORD, &add_cmd},
	{TK_PIPE, &add_sep},
	{TK_BANG, &add_cmd},
	{TK_SEMI, &add_sep},
	{TK_GREAT, &add_cmd},
	{TK_LESS, &add_cmd},
	{TK_GREATAND, &add_cmd},
	{TK_LESSAND, &add_cmd},
	{TK_DGREAT, &add_cmd},
	{TK_DLESS, &add_cmd},
	{TK_IO_NUMBER, &add_cmd},
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
	{TK_NAME, &add_cmd},
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
	return (1);
}

static int	check_cache(t_token *token, int cache)
{
	if (token->type == TK_ASSIGNEMENT_WORD && cache == TK_WORD)
		token->type = TK_WORD;
	if (token->type == TK_PAREN_OPEN && cache != TK_IN && cache != TK_DSEMI
		&& cache != TK_WORD)
		token->type = SUBSHELL;
	return (0);
}

int			build_tree(t_btree **ast, t_list **lst)
{
	int				i;
	static int		cache;
	t_token			*token;

	i = 0;
	token = (*lst)->content;
	check_cache(token, cache);
	while (g_treematch[i].type)
	{
		if ((isseparator(token, cache) && g_treematch[i].type == token->type))
		{
			DG("build %s", read_state(g_treematch[i].type));
			cache = token->type;
			return (g_treematch[i].add(ast, lst));
		}
		i++;
	}
	return (0);
}
