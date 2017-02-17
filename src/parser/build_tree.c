/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:32:59 by ariard            #+#    #+#             */
/*   Updated: 2017/02/17 23:34:15 by ariard           ###   ########.fr       */
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
	{0, NULL},
};

int		build_tree(t_btree **ast, t_list **lst)
{
	int		i;
	t_token	*token;

	i = 0;
	token = (*lst)->content;
	while (g_treematch[i].type)
	{
		if (g_treematch[i].type == token->type)
		{
		
			DG("func TK : '%s' TK : '%s'",
			read_state(g_treematch[i].type) ,read_state(token->type));
		   return (g_treematch[i].add(ast, lst));
		}
		i++;
	}
	return (0);
}
