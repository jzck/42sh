/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:30:08 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 18:28:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	g_parser[] =
{
	{TK_SEMI, &parse_separator},
	{TK_PIPE, &parse_separator},
	{TK_LESS, &parse_less},
	{TK_GREAT, &parse_great},
	{TK_DLESS, &parse_dless},
	{TK_DGREAT, &parse_dgreat},
	{TK_LESSAND, &parse_lessand},
	{TK_GREATAND, &parse_greatand},
	{TK_WORD, &parse_word},
	{0, 0},
};

int		ft_parse(t_btree **ast, t_list *start)
{
	t_list		*lst;
	t_astnode	item;
	int			i;

	i = 0;
	if(!start)
		return (0);
	if (!*ast)
		*ast = btree_create_node(&item, sizeof(item));
	while (g_parser[i].type)
	{
		if ((lst = ft_lst_find(start, &g_parser[i].type, &token_cmp_type)))
		{
			item.type = g_parser[i].type;
			if (g_parser[i].f)
				(*g_parser[i].f)(ast, start, lst);
			return (0);
		}
		else
			i++;
	}
	return (0);
}
